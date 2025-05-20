/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by clyon             #+#    #+#             */
/*   Updated: 2025/05/20 00:00:00 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	process_files(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 1;
	while (i < argc)
	{
		map = ft_create_map(argv[i]);
		if (map)
			ft_process_map(map, argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

static void	process_stdin(void)
{
	t_map	*map;

	map = ft_create_map("STDIN");
	if (map)
		ft_process_map(map, "STDIN");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		process_stdin();
	else
		process_files(argc, argv);
	return (0);
}
