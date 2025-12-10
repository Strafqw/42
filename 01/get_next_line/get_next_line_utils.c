/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:50:10 by joasampa          #+#    #+#             */
/*   Updated: 2025/12/10 17:43:47 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int find_newline(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

size_t	gnl_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join_and_free(char *stash, char *buf)
{
	char	*newstash;
	size_t	i;
	size_t	j;

	newstash = malloc(gnl_strlen(stash) + gnl_strlen(buf) + 1);
	if (!newstash)
		return (NULL);
	i = 0;
	while (stash && stash[i])
	{
		newstash[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		newstash[i + j] = buf[j];
		j++;
	}
	newstash[i + j] = '\0';
	if (stash)
		free(stash);
	return (newstash);
}

char *extract_line(char *stash)
{
    int i;
    int len;
    char *line;
    int j;
    
    if (!stash || !stash[0])
        return (NULL);
    j = 0;
    i = find_newline(stash);
    if (i >= 0)
        len = i + 1;
    else
        len = gnl_strlen(stash);
    line = malloc(len + 1);
    if (!len)
        return (NULL);
    while (j < len)
    {
        line[j] = stash[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}
