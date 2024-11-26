/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:20:31 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/26 11:21:05 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	int			byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	tmp = NULL;
	byte = 0;
	byte = read_line(fd, &line, byte);
	if (byte == BUFFER_SIZE || find_nl(line) >= 0)
	{
		tmp = get_new_line(line);
		if (tmp == NULL && line != NULL)
			return (free_null(&line));
		clear_line(&line);
		return (tmp);
	}
	if (byte != -1 && line != NULL && ft_strlen(line) >= 1)
		tmp = ft_strndup(line, ft_strlen(line));
	if (line != NULL)
		free_null(&line);
	if (byte == -1)
		return (NULL);
	return (tmp);
}

void	clear_line(char **line)
{
	char	*new;
	int		line_len;

	line_len = 0;
	while ((*line)[line_len] != '\n')
		line_len++;
	line_len += 1;
	new = ft_strndup(*line + line_len, ft_strlen(*line + line_len));
	free(*line);
	*line = new;
}

char	*get_new_line(char *line)
{
	char	*new;
	int		len;

	len = 0;
	while (line[len] != '\n')
		len++;
	len++;
	new = ft_strndup(line, len);
	return (new);
}

int	read_line(int fd, char **line, int byte)
{
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && find_nl(*line) == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
		{
			free(buff);
			return (byte);
		}
		buff[byte] = '\0';
		tmp = ft_strjoin(*line, buff);
		free(*line);
		*line = tmp;
	}
	free(buff);
	return (byte);
}
