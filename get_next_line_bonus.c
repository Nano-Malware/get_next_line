/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourjal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:46:01 by rbourjal          #+#    #+#             */
/*   Updated: 2026/11/21 19:00:11 by rbourjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_all(char *a, char *b)
{
	free(a);
	free(b);
	return (NULL);
}

static char	*extract_line(char *stash)
{
	size_t	len;

	if (!stash[0])
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (gnl_substr(stash, 0, len));
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free_all(stash, NULL));
	bytes = 1;
	while (!gnl_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free_all(stash, buf));
		buf[bytes] = 0;
		stash = gnl_strjoin(stash, buf);
		if (!stash)
			return (free_all(buf, NULL));
	}
	free(buf);
	return (stash);
}

static char	*trim_stash(char *stash)
{
	char	*n;
	char	*rest;

	n = gnl_strchr(stash, '\n');
	if (!n || !n[1])
		return (free_all(stash, NULL));
	rest = gnl_substr(n + 1, 0, gnl_strlen(n + 1));
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = trim_stash(stash[fd]);
	return (line);
}
