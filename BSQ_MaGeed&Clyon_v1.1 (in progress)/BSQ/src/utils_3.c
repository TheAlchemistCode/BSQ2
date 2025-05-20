/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by clyon             #+#    #+#             */
/*   Updated: 2025/05/20 00:00:00 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	read_header_row(int fd, char *rows, char *buffer)
{
	char	*row_ptr;
	int		read_ret;

	row_ptr = rows;
	read_ret = read(fd, buffer, 1);
	while (read_ret > 0 && *buffer != '\n')
	{
		if (row_ptr - rows < 12)
			*row_ptr++ = *buffer;
		read_ret = read(fd, buffer, 1);
	}
	*row_ptr = '\0';
	return (row_ptr - rows);
}

int	read_first_map_line(int fd, int *col_count, char *buffer)
{
	int	read_ret;

	*col_count = 0;
	read_ret = read(fd, buffer, 1);
	while (read_ret > 0 && *buffer != '\n')
	{
		(*col_count)++;
		read_ret = read(fd, buffer, 1);
	}
	return (0);
}

int	open_map_fd(const char *file_name)
{
	if (file_name[0] == 'S')
		return (STDIN_FILENO);
	return (open(file_name, O_RDONLY));
}
