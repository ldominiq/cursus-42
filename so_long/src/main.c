#include "so_long.h"

int	main(int argc, char *argv[])
{
	int			fd;
    static char *map;

	if (ft_errors(argc))
		return (1);
	if (!map)
		map = ft_strdup("");
	fd = open_file(argv[1]);
	if (fd == -1)
		return (1);
	read_map(fd, &map);
	ft_free_ptr(&map);
	close(fd);
    return (0);
}
