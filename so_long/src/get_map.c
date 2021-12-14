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

void	read_map(int fd, char **map, void *mlx)
{
	char	*tmp;
	int		height;
	int		width;

	tmp = "";
	height = 0;
	width = 0;
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			printf("%s", tmp);
			map = ft_strjoin(map, tmp);
		}
	}
	ft_new_window();
}