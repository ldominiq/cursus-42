#include "so_long.h"
#include <stdlib.h>

int ft_close()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window    window;

	/* This mlx function creates a returns a pointer
	to a new window with a given size and name */
	window.size.x = width * 32;
	window.size.y = height * 32;
	window.reference = mlx_new_window(mlx, window.size.x, window.size.y, name);

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}