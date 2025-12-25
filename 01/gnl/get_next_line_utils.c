/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:11:19 by joasampa          #+#    #+#             */
/*   Updated: 2025/12/23 16:06:06 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*joinfree(char *stash, char *buf)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = malloc(gnl_strlen(stash) + gnl_strlen(buf) + 1);
	if (!newstr)
		return (free(stash), NULL);
	i = 0;
	while (stash && stash[i])
	{
		newstr[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf && buf[j])
		newstr[i++] = buf[j++];
	newstr[i] = '\0';
	free(stash);
	return (newstr);
}

char	*extractline(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = stash[i];
	return (line);
}

char	*extractstash(char *stash)
{
	int		i;
	int		j;
	char	*new;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	i++;
	new = malloc(gnl_strlen(stash + i) + 1);
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*read_to_stash(int fd, char *stash, char *buf)
{
	ssize_t	bytes;
	int		i;

	bytes = 1;
	while (bytes > 0)
	{
		i = 0;
		while (stash && stash[i] && stash[i] != '\n')
			i++;
		if (stash && stash[i] == '\n')
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = joinfree(stash, buf);
		if (!stash)
			return (NULL);
	}
	if (bytes < 0)
		return (free(stash), NULL);
	return (stash);
}
