#include "so_long.h"

/* Returns an image with the sprite found in <path> */
t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates and image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void ft_create_ground(t_program *program)
{
    int			i;
	int			j;

	i = 0;
	j = 0;
    while (i < 50)
	{
		while (j < 50)
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->ground_sprite.sprite.reference, program->ground_sprite.sprite_position.x, program->ground_sprite.sprite_position.y);
			program->ground_sprite.sprite_position.x += program->ground_sprite.sprite.size.x;
			j++;
		}
		i++;
		j = 0;
		program->ground_sprite.sprite_position.y += program->ground_sprite.sprite.size.y;
		program->ground_sprite.sprite_position.x = 0;
	}
}