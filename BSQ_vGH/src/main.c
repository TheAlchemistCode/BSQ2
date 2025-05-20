#include "bsq.h"

static void	process_stdin(void)
{
    t_map	*map;

    map = ft_create_map("STDIN");
    if (map)
        ft_process_map(map);
}

static void	process_files(int argc, char **argv)
{
    t_map	*map;
    int		i;

    i = 1;
    while (i < argc)
    {
        map = ft_create_map(argv[i]);
        if (map)
            ft_process_map(map);
        if (i < argc - 1)
            write(1, "\n", 1);
        i++;
    }
}

int	main(int argc, char **argv)
{
    if (argc < 2)
        process_stdin();
    else
        process_files(argc, argv);
    return (0);
}