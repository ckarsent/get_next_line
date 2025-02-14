/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:34:24 by ckarsent          #+#    #+#             */
/*   Updated: 2024/12/12 17:51:36 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	i;

	i = 0;
	c = malloc(count * size);
	if (!c)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)c)[i] = 0;
		i++;
	}
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new)
		return (NULL);
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (00);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*c;

	c = malloc(sizeof(char) * (len + 1));
	if (!c || !s)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		c[i] = s[i + start];
		i++;
	}
	c[i] = '\0';
	return (c);
}
