/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by clyon             #+#    #+#             */
/*   Updated: 2025/05/20 00:00:00 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <string.h> // for strlen
#include <stdlib.h> // for malloc

int		parse_header(t_map *map, int fd);
t_map	*ft_create_map(const char *file_name);
int		ft_read_matrix(t_map *map, int fd);

int	parse_header(t_map *map, int fd)
{
	char	buffer;
	char	rows[13];
	char	*row_ptr;
	int		col_count;

	col_count = 0;
	row_ptr = rows;
	if (read_header_row(fd, rows, &buffer) < 4)
		return (1);
	row_ptr = rows + strlen(rows);
	map->full = *(--row_ptr);
	map->obstacle = *(--row_ptr);
	map->empty = *(--row_ptr);
	*row_ptr = '\0';
	if (!is_number(rows) || map->empty == map->obstacle)
		return (1);
	map->rows = ft_atoi(rows);
	if (read_first_map_line(fd, &col_count, &buffer))
		return (1);
	map->cols = col_count;
	lseek(fd, -(col_count + 1), SEEK_CUR);
	if (map->rows <= 0 || map->cols <= 0)
		return (1);
	return (0);
}

int	ft_read_matrix(t_map *map, int fd)
{
	int		row;
	int		ret;

	row = 0;
	ret = 0;
	while (row < map->rows)
	{
		ret = ft_read_matrix_line(map, fd, row);
		if (ret)
			return (1);
		row++;
	}
	return (0);
}

t_map	*ft_create_map(const char *file_name)
{
	t_map	*map;
	int		fd;
	int		ret;

	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_map_error());
	fd = open_map_fd(file_name);
	ret = init_map_and_check(map, fd);
	if (ret)
	{
		if (fd != STDIN_FILENO && fd >= 0)
			close(fd);
		return (ft_map_error());
	}
	close(fd);
	return (map);
}
