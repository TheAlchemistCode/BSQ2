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

#ifndef BSQ_H
# define BSQ_H

# include <stddef.h>
# include <unistd.h>

// Structure for the map
typedef struct s_map
{
	int					rows;
	int					cols;
	unsigned short		**matrix;
	char				empty;
	char				obstacle;
	char				full;
	int					square_size;
	int					square_row;
	int					square_col;
}	t_map;

// utils.c
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
t_map	*ft_map_error(void);

// utils_2.c
int		is_number(const char *str);
int		allocate_matrix(t_map *map);
int		read_header_row(int fd, char *rows, char *buffer);
int		read_first_map_line(int fd, int *col_count, char *buffer);
int		open_map_fd(const char *file_name);
int		ft_read_matrix_line(t_map *map, int fd, int row);

// utils_3.c
// (add any functions you have here, e.g.)
// int		another_helper(...);

// utils_4.c
int		ft_process_matrix_char(t_map *map, char buffer, int row, int col);
int		ft_read_matrix(t_map *map, int fd);
void	ft_free_map(t_map *map);
int		init_map_and_check(t_map *map, int fd);

// map_parser.c
int		parse_header(t_map *map, int fd);
t_map	*ft_create_map(const char *file_name);

// solver.c
void	ft_get_square(t_map *map);

// printer.c
void	ft_process_map(t_map *map, const char *file_name);

#endif