#include "so_long.h"

int	open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (!check_map_name(file_name))
	{
		printf("Error\nMap extension is incorrect. (.ber)\n");
		return (-1);
	}
	if (fd == -1)
	{
		printf("Error\nAn error occurred when opening the map file.\n");
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
		check_map_shape(width, tmp, map);
		tmp = get_next_line(fd);
	}
	if(check_map_validity(map) && check_map_border(map, width))
		ft_new_window(width, height, map);
	ft_free_ptr(map);
}