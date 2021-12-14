#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program 	program;
	int			fd;

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
	fd = open_file(argv[1]);
	printf("fd: %d\n", fd);
	read_map(fd);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 720, 480, "Yeet");
	program.ground_sprite.sprite = ft_new_sprite(program.mlx, "./img/grass.xpm");
	program.player_sprite.sprite = ft_new_sprite(program.mlx, "./img/trainer.xpm");
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
