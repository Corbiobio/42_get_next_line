/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:54:05 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/21 12:45:44 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	c_in_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new[i + s1_len] = s2[i];
		i++;
	}
	new[s1_len + s2_len] = '\0';
	return (new);
}

int	fill_line(char **line, char *buff, int byte, int fd)
{
	char	*tmp;
	int		count;

	byte = read(fd, buff, BUFFER_SIZE);
	buff[byte] = '\0';
	count = 0;
	printf("%d byte", byte);

	while (byte >= 1)
	{
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
		if ((c_in_str(*line, '\n') >= 0 || byte < BUFFER_SIZE))
		//if (c_in_str(*line, '\n') >= 0 || byte < BUFFER_SIZE)
			return (byte);
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
		count++;
	}
	if (count >= 1)
		return (byte);
	return (-1);
}

char	*clear_line(char **line)
{
	char	*new;
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	while ((*line)[len] != '\n')
		len++;
	len++;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = (*line)[i];
		i++;
	}
	new[len] = '\0';
	tmp = *line;
	*line = get_line_after_newline(line);
	free(tmp);
	return (new);
}

char	*get_line_after_newline(char **line)
{
	int		len;
	int		start;
	int		i;
	char	*new;

	len = ft_strlen(*line);
	start = 0;
	while ((*line)[start] != '\n')
		start++;
	start++;
	new = malloc(sizeof(char) * (len - start + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len - start)
	{
		new[i] = (*line)[i + start];
		i++;
	}
	new[len - start] = '\0';
	return (new);
}
