// filepath: c:\Users\User\Desktop\Q_code\BSQ\BSQ\include\bsq.h
#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// Structure for the map
typedef struct s_map
{
    int				rows;
    int				cols;
    char			empty;
    char			obstacle;
    char			full;
    unsigned short	**matrix;
    unsigned short	square_size;
    int				square_row;
    int				square_col;
}					t_map;

// Function prototypes
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
t_map	*ft_map_error(void);
void	ft_free_map(t_map *map);
void	ft_get_square(t_map *map);
void	ft_process_map(t_map *map, const char *file_name); // Updated declaration
int		ft_get_line(t_map *map, int row, int file_name);
int		ft_get_first_line(t_map *map, int file_name);
int		ft_get_matrix(t_map *map, int file_name);
int		ft_map_header(t_map *map, int file_name);
t_map	*ft_create_map(const char *file_name);

#endif