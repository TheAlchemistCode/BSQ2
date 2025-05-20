/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
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

int	is_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	allocate_matrix(t_map *map)
{
	int	i;

	i = 0;
	map->matrix = malloc(map->rows * sizeof(unsigned short *));
	if (!map->matrix)
		return (1);
	while (i < map->rows)
	{
		map->matrix[i] = malloc(map->cols * sizeof(unsigned short));
		if (!map->matrix[i])
			return (1);
		i++;
	}
	return (0);
}
