/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by clyon             #+#    #+#             */
/*   Updated: 2025/05/20 00:00:00 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	min_value(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= c)
		return (b);
	return (c);
}

static void	update_square(t_map *map, int row, int col)
{
	if (map->matrix[row][col] > map->square_size)
	{
		map->square_size = map->matrix[row][col];
		map->square_row = row;
		map->square_col = col;
	}
}

void	ft_get_square(t_map *map)
{
	int	row;
	int	col;

	map->square_size = 0;
	map->square_row = 0;
	map->square_col = 0;
	row = 1;
	while (row < map->rows)
	{
		col = 1;
		while (col < map->cols)
		{
			if (map->matrix[row][col] != 0)
			{
				map->matrix[row][col] += min_value(
						map->matrix[row - 1][col],
						map->matrix[row][col - 1],
						map->matrix[row - 1][col - 1]);
				update_square(map, row, col);
			}
			col++;
		}
		row++;
	}
}
