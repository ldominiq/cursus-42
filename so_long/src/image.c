#include "so_long.h"

void	ft_init_sprite(char *path, int x, int y, t_program *program)
{
	int 	width;
	int 	height;
	char 	*img;

	img = mlx_xpm_file_to_image(program->mlx, path, &width, &height);
	mlx_put_image_to_window(program->mlx, program->window.reference, img, x, y);
}

void	ft_new_sprite(t_program *program, char *tile_path, int type)
{
	int i;
	int	x;
	int y;

	x = -1;
	y = -1;
	i = -1;
	while (program->window.size.y > ++y)
	{
		while ((program->map->map)[++i] && program->window.size.x > ++x)
		{
			printf("OK--\n");
			if ((program->map->map)[i] == type || type == 'G')
				ft_init_sprite(tile_path, x * SPRITE_SIZE, y * SPRITE_SIZE, program);
		}
		x = -1;
	}
}