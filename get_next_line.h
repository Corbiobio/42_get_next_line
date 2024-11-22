/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:54:05 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/22 17:41:59 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		find_nl(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		read_line(int fd, char **line, int byte);
char	*get_new_line(char *line);
void	clear_line(char **line);
char	*ft_strndup(char *s, int n);

#endif