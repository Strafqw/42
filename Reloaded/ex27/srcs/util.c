/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:33:38 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/16 12:33:40 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_file(int fd)
{
	size_t	read_bytes;
	char	buffer[1025];

	read_bytes = read(fd, buffer, 1024);
	while (read_bytes > 0)
	{
		write(1, buffer, read_bytes);
		read_bytes = read(fd, buffer, 1024);
	}
}
