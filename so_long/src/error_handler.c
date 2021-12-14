#include "so_long.h"

int	ft_errors(int argc)
{
	if (argc > 2)
	{
		printf("Too many arguments.\n");
		ft_close();
		return (1);
	}
	else if (argc == 1)
	{
		printf("Please enter a map: ./so_long path/map.ber\n");
		ft_close();
		return (1);
	}
	return (0);
}