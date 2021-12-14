#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	program;
	int			fd;

	if (ft_errors(argc))
		return (1);
	fd = open_file(argv[1]);
	printf("fd: %d\n", fd);
	read_map(fd);
	program.mlx = mlx_init();
	program.ground_sprite.sprite = ft_new_sprite(program.mlx,
			"./img/grass.xpm");
	program.player_sprite.sprite = ft_new_sprite(program.mlx,
			"./img/trainer.xpm");
	program.ground_sprite.sprite_position.x = 0;
	program.ground_sprite.sprite_position.y = 0;
	program.player_sprite.sprite_position.x = 0;
	program.player_sprite.sprite_position.y = 0;
	ft_create_ground(&program);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.player_sprite.sprite.reference,
		program.player_sprite.sprite_position.x,
		program.player_sprite.sprite_position.y);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	//mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
