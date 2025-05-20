#include "bsq.h"
#include <stdio.h> // For printf

#define SQUARE_MARKER 65535 // Use a distinct positive value for marking the square

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
            map->matrix[row][col] = SQUARE_MARKER; // Mark square cells
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
                cell = map->full; // Use the 'full' character for the largest square
            else if (map->matrix[row][col] == 0)
                cell = map->obstacle; // Use the 'obstacle' character
            else
                cell = map->empty; // Use the 'empty' character

            write(1, &cell, 1); // Print the character
            col++;
        }
        write(1, "\n", 1); // Move to the next row
        row++;
    }
}

static void	debug_map(t_map *map, const char *file_name)
{
    int		row;
    int		col;

    // Print the dynamic message with the map file name
    printf("I am checking %s!\n", file_name);

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->cols)
        {
            if (map->matrix[row][col] == 0)
                write(1, "o", 1); // Print obstacle
            else
                write(1, ".", 1); // Print empty space
            col++;
        }
        write(1, "\n", 1); // Move to the next row
        row++;
    }
}

void	ft_process_map(t_map *map, const char *file_name)
{
    debug_map(map, file_name); // Print the initial map with the file name
    ft_get_square(map);        // Find the largest square
    fill_square(map);          // Mark the largest square in the matrix
    print_map(map);            // Print the final map
    ft_free_map(map);          // Free allocated memory
}