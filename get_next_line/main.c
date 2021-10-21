#include "get_next_line.c"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error\n");
		return (1);
	}
	get_next_line(fd);
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	return (0);
}