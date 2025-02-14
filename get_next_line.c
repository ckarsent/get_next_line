/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:34:29 by ckarsent          #+#    #+#             */
/*   Updated: 2025/01/30 14:06:07 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract(char *ou)
{
	char	*line;

	if (!ou || *ou == '\0')
		return (NULL);
	line = ft_strchr(ou, '\n');
	if (line)
		return (ft_substr(ou, 0, line - ou + 1));
	return (ft_substr(ou, 0, ft_strlen(ou)));
}

static char	*ft_save(char *ou)
{
	char	*new_li;
	char	*new_ou;

	new_li = ft_strchr(ou, '\n');
	if (!new_li)
	{
		free(ou);
		return (NULL);
	}
	new_ou = ft_substr(ou, new_li - ou + 1, ft_strlen(ou) - (new_li - ou + 1));

	free(ou);
	return (new_ou);
}

static char	*ft_join(char *ou, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(ou, buffer);
	free(ou);
	return (tmp);
}

static char	*ft_read(int fd, char *ou)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		free(ou);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!ou)
			ou = ft_calloc(1, 1);
		ou = ft_join(ou, buffer);
		if (ft_strchr(ou, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ou);
}

char	*get_next_line(int fd)
{
	static char	*ou;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ou = ft_read(fd, ou);
	if (!ou)
		return (NULL);
	line = ft_extract(ou);
	ou = ft_save(ou);
	return (line);
}


#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *tmp;

		while ((tmp = get_next_line(fd)))
		{
			printf("%s", tmp);
			free(tmp);
		}
	}
	return (0);
}
