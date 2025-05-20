// filepath: c:\Users\User\Desktop\Q_code\BSQ\BSQ_vGH\src\map_parser.c
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h> // Added for debugging statements

static bool	is_number(const char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (false);
        str++;
    }
    return (true);
}

static int	parse_header(t_map *map, int fd)
{
    char	buffer;
    char	rows[13];
    char	*row_ptr;
    int		col_count = 0;

    row_ptr = rows;
    while (read(fd, &buffer, 1) > 0 && buffer != '\n')
    {
        if (row_ptr - rows < 12)
            *row_ptr++ = buffer;
    }
    *row_ptr = '\0'; // Null-terminate the rows string
    printf("Header: %s\n", rows); // Debugging statement

    if (row_ptr - rows < 4)
        return (1);
    map->full = *(--row_ptr);
    map->obstacle = *(--row_ptr);
    map->empty = *(--row_ptr);
    *row_ptr = '\0';
    if (!is_number(rows) || map->empty == map->obstacle)
        return (1);
    map->rows = ft_atoi(rows);
    printf("Rows: %d, Empty: %c, Obstacle: %c, Full: %c\n",
        map->rows, map->empty, map->obstacle, map->full); // Debugging statement

    // Calculate the number of columns by reading the first row
    while (read(fd, &buffer, 1) > 0 && buffer != '\n')
        col_count++;
    map->cols = col_count;
    printf("Cols: %d\n", map->cols); // Debugging statement

    // Reset the file descriptor to the start of the map content
    lseek(fd, -(col_count + 1), SEEK_CUR);

    return (map->rows <= 0 || map->cols <= 0);
}

static int	allocate_matrix(t_map *map)
{
    map->matrix = malloc(map->rows * sizeof(unsigned short *));
    if (!map->matrix)
    {
        printf("Failed to allocate memory for rows\n");
        return (1);
    }
    for (int i = 0; i < map->rows; i++)
    {
        map->matrix[i] = malloc(map->cols * sizeof(unsigned short));
        if (!map->matrix[i])
        {
            printf("Failed to allocate memory for row %d\n", i);
            return (1);
        }
    }
    printf("Matrix allocated with %d rows and %d cols\n", map->rows, map->cols);
    return (0);
}

int	ft_get_matrix(t_map *map, int fd)
{
    char	buffer;
    int		row = 0;
    int		col = 0;

    while (read(fd, &buffer, 1) > 0)
    {
        if (buffer == '\n')
        {
            if (col != map->cols) // Ensure each row has the correct number of columns
                return (1);
            row++;
            col = 0;
            continue;
        }
        if (row >= map->rows) // Ensure the number of rows matches the header
            return (1);
        if (buffer == map->empty)
            map->matrix[row][col] = 1; // Mark empty spaces
        else if (buffer == map->obstacle)
            map->matrix[row][col] = 0; // Mark obstacles
        else
            return (1); // Invalid character
        col++;
    }
    if (row != map->rows) // Ensure the number of rows matches the header
        return (1);

    // Debugging output removed
    return (0);
}

t_map	*ft_create_map(const char *file_name)
{
    t_map	*map;
    int		fd;

    map = malloc(sizeof(t_map));
    if (!map)
        return (ft_map_error());
    fd = (file_name[0] == 'S') ? STDIN_FILENO : open(file_name, O_RDONLY);
    if (fd < 0 || parse_header(map, fd) || allocate_matrix(map) || ft_get_matrix(map, fd))
        return (ft_map_error());
    close(fd);
    return (map);
}