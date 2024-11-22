/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:46:04 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/22 17:42:39 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == '\n')
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

char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (new == NULL)
		return (NULL);
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
