/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:20:31 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/22 15:55:41 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	int			byte;

	tmp = NULL;
	byte = 0;
	byte = read_line(fd, &line, byte);
	if (byte == -1)
	{
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
	if (byte == BUFFER_SIZE || c_in_str(line, '\n') >= 0)
	{
		tmp = get_new_line(line);
		//printf("__tmp %s__", tmp);
		clear_line(&line);
		return (tmp);
	}
	if (line != NULL && ft_strlen(line) >= 1)
		tmp = ft_strdup(line);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (tmp);
}

void	clear_line(char **line)
{
	char	*new;
	int		line_len;

	line_len = 0;
	while ((*line)[line_len] != '\n')
		line_len++;
	line_len++;
	new = ft_strdup(*line + line_len);
	free(*line);
	*line = new;
}

char	*get_new_line(char *line)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	while (line[len] != '\n')
		len++;
	len++;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}

int	read_line(int fd, char **line, int byte)
{
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-10);
	buff[BUFFER_SIZE] = '\0';
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && c_in_str(*line, '\n') == -1)
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

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*new;

	len = ft_strlen(s);
	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
