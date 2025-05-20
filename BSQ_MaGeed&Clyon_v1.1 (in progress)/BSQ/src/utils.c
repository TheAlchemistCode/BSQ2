// filepath: c:\Users\User\Desktop\Q_code\BSQ\BSQ_vGH\src\utils.c
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
    unsigned char		*d;
    const unsigned char	*s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    while (num--)
        *d++ = *s++;
    return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void	*new_ptr;

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);
    if (ptr)
    {
        ft_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
        free(ptr);
    }
    return (new_ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_atoi(const char *str)
{
    int	num;
    int	sign;

    num = 0;
    sign = 1;
    while ((*str >= '\t' && *str <= '\r') || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return (sign * num);
}

t_map	*ft_map_error(void)
{
    write(STDERR_FILENO, "map error\n", 10);
    return (NULL);
}

void	ft_free_map(t_map *map)
{
    int	row;

    if (!map)
        return;
    row = 0;
    while (row < map->rows)
    {
        free(map->matrix[row]);
        row++;
    }
    free(map->matrix);
    free(map);
}