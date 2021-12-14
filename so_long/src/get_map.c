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

int	read_map(int fd)
{
	char	*str;

	str = "";
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s", str);
	}
	return (0);
}