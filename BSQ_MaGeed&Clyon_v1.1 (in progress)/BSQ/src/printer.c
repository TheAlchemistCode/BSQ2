/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by clyon             #+#    #+#             */
/*   Updated: 2025/05/20 00:00:00 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

#define SQUARE_MARKER 65535

static void	fill_square(t_map *map)
{
	int	row;
	int	col;

	row = map->square_row - map->square_size + 1;
	while (row <= map->square_row)
	{
		col = map->square_col - map->square_size + 1;
		while (col <= map->square_col)
		{
			map->matrix[row][col] = SQUARE_MARKER;
			col++;
		}
		row++;
	}
}

static void	print_map(t_map *map)
{
	int		row;
	int		col;
	char	cell;

	printf("I found a big square here!\n");
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (map->matrix[row][col] == SQUARE_MARKER)
				cell = map->full;
			else if (map->matrix[row][col] == 0)
				cell = map->obstacle;
			else
				cell = map->empty;
			write(1, &cell, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

static void	debug_map(t_map *map, const char *file_name)
{
	int		row;
	int		col;

	printf("I am checking %s!\n", file_name);
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (map->matrix[row][col] == 0)
				write(1, "o", 1);
			else
				write(1, ".", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	ft_process_map(t_map *map, const char *file_name)
{
	debug_map(map, file_name);
	ft_get_square(map);
	fill_square(map);
	print_map(map);
	ft_free_map(map);
}
