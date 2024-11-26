/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:54:05 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/21 12:22:28 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*buff;
	int			byte;

	line = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	byte = 0;
	byte = fill_line(&next_line, buff, byte, fd);
	if (byte < 0)
	{
		free(buff);
		return (NULL);
	}
	if (c_in_str(next_line, '\n') >= 0)
	{
		free(buff);
		line = clear_line(&next_line);
		return (line);
	}
	free(buff);
	return (next_line);
}

//int	main(void)
//{
//	char	*s;
//	int		o;
//	int		i;

//	i = 0;
//	o = open("test.txt", O_RDONLY);

//	while (i < 2)
//	{
//		s = get_next_line(o);
//		//printf("%s--", s);
//		free(s);
//		i++;
//	}
//	close(o);
//	return (0);
//}
