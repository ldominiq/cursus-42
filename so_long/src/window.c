#include "so_long.h"
#include <stdlib.h>

int ft_close()
{
	exit(0);
}

int	ft_new_window(int width, int height, char **map)
{
	t_program   *program;

    program = malloc(sizeof(t_program));
    if (!program)
        return (0);
    ft_init(program);
	program->window.size.x = width;
	program->window.size.y = height;
    program->map->map = *map;
	program->mlx = mlx_init();
	program->window.reference = mlx_new_window(program->mlx,
                                               program->window.size.x * SPRITE_SIZE,
                                               program->window.size.y * SPRITE_SIZE, "Yeet");
    ft_init_map(program);
	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(program->window.reference, 17, 0, ft_close, 0);
    mlx_key_hook(program->window.reference, *ft_input, program);
    mlx_loop(program->mlx);
	return (0);
}