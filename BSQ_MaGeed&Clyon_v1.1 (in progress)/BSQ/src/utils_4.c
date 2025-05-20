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
#include <stdlib.h>
#include <unistd.h>

int		ft_process_matrix_char(t_map *map, char buffer, int row, int col);
int		ft_read_matrix_line(t_map *map, int fd, int row);
int		ft_read_matrix(t_map *map, int fd);
void	ft_free_map(t_map *map);
int		init_map_and_check(t_map *map, int fd);

int	ft_process_matrix_char(t_map *map, char buffer, int row, int col)
{
	if (buffer == map->empty)
		map->matrix[row][col] = 1;
	else if (buffer == map->obstacle)
		map->matrix[row][col] = 0;
	else
		return (1);
	return (0);
}

int	ft_read_matrix_line(t_map *map, int fd, int row)
{
	char	buffer;
	int		col;
	int		read_ret;

	col = 0;
	read_ret = read(fd, &buffer, 1);
	while (read_ret > 0 && buffer != '\n')
	{
		if (ft_process_matrix_char(map, buffer, row, col))
			return (1);
		col++;
		read_ret = read(fd, &buffer, 1);
	}
	if (col != map->cols)
		return (1);
	return (0);
}

void	ft_free_map(t_map *map)
{
	int	row;

	if (!map)
		return ;
	row = 0;
	while (row < map->rows)
	{
		free (map->matrix[row]);
		row++;
	}
	free(map->matrix);
	free(map);
}

int	init_map_and_check(t_map *map, int fd)
{
	if (fd < 0)
		return (1);
	if (parse_header(map, fd))
		return (1);
	if (allocate_matrix(map))
		return (1);
	if (ft_read_matrix(map, fd))
		return (1);
	return (0);
}
