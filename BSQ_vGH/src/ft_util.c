#include "bsq.h"

// Displays the error message
t_map	*ft_map_error(void)
{
	write(STDERR_FILENO, "map error\n", 10);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
    size_t  i;
    unsigned char       *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;
    while (i < num)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*tmp;

	// Temp receives memory allocation for the new size
	tmp = malloc(new_size);

	// Copy all ptr memory data to tmp
	ft_memcpy(tmp, ptr, (old_size < new_size) ? old_size : new_size);

	// free the pointer
	free(ptr);
	return (tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    size_t  i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int				ft_atoi(const char *str)
{
    int     i;
    int     sign;
    int     res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}