#include "so_long.h"

int	open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("An error occurred when opening the map.");
		return (fd);
	}
	return (fd);
}

void	read_map(int fd, char **map)
{
	char	*tmp;
	int		height;
	int		width;

	height = 0;
	width = 0;
	tmp = get_next_line(fd);
	width = ft_strchr_pos(tmp, '\n');
	while (tmp != NULL)
	{
		height++;
		*map = ft_strjoin(*map, tmp);
		tmp = get_next_line(fd);
	}
	ft_new_window(width, height, map);
}