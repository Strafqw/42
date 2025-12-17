/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:50:03 by joasampa          #+#    #+#             */
/*   Updated: 2025/12/17 13:17:12 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	stash[fd] = read_to_stash(fd, stash[fd], buf);
	free(buf);
	if (!stash[fd] || !stash[fd][0])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extractline(stash[fd]);
	stash[fd] = extractstash(stash[fd]);
	return (line);
}
