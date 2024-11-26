/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:35:42 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/19 16:42:59 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*tmp;
	char		*buffer;
	ssize_t		byte;
	int			i;

	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	byte = BUFFER_SIZE;
	while (byte >= BUFFER_SIZE)
	{
		tmp = NULL;
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
			return (clear(buffer));
		tmp = ft_strjoin(next_line, buffer);
		if (i != 0)
			clear(next_line);
		i++;
		next_line = tmp;
		if (ft_strchr(next_line, '\n'))
		{
			tmp = parse_line(&next_line);
			clear(buffer);
			clear(next_line);
			next_line = tmp;
			return (next_line);
		}
	}
	printf("tests");
	return (clear(buffer));
}

char	*parse_line(char **s)
{
	int		new_len;
	int		i;
	char	*new;

	new_len = 0;
	while ((*s)[new_len] != '\n')
		new_len++;
	new = malloc(sizeof(char) * new_len + 2);
	if (new == NULL)
		return (NULL);
	new[new_len] = '\n';
	new[new_len + 1] = '\0';
	i = 0;
	while (i < new_len)
	{
		new[i] = (*s)[i];
		i++;
	}
	*s = *s + new_len + 1;
	return (new);
}

int	main(void)
{
	int	o;
	char *s;

	o = open("test.txt", O_RDWR);
	//if (o >= 0)
	//get_next_line(o);
	//get_next_line(o);
	//get_next_line(o);
	s = get_next_line(o);
	printf("%s", s);
	free(s);
	s = get_next_line(o);
	printf("%s", s);
	free(s);
	s = get_next_line(o);
	printf("%s", s);
	free(s);
	s = get_next_line(o);
	printf("%s", s);
	free(s);
	s = get_next_line(o);
	printf("%s", s);
	free(s);
		s = get_next_line(o);
	printf("%s", s);
	free(s);
	s = get_next_line(o);
	//printf("%s", s);
	free(s);
		//printf("%s", get_next_line(o));
		//printf("%s", get_next_line(o));
		//printf("%s", get_next_line(o));
		//printf("%s", get_next_line(o));
	//	get_next_line(o);
	//char *s = NULL;
	//printf("%d\n", ft_strlen(s));
	close(o);
	return (0);
}
