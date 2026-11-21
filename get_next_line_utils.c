/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourjal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:44:47 by rbourjal          #+#    #+#             */
/*   Updated: 2026/11/21 18:46:45 by rbourjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *stash, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(gnl_strlen(buf) + gnl_strlen(stash) + 1);
	if (!res)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
		res[i++] = buf[j++];
	res[i] = 0;
	free(stash);
	return (res);
}

char	*gnl_substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*res;

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
