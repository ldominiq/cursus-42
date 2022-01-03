#include "so_long.h"

void	ft_init(t_program *program)
{
	program->map = malloc(sizeof(t_map));
	program->map->balls = malloc(sizeof(t_balls));
	program->player = malloc(sizeof(t_player));
	program->player->player_pos = malloc(sizeof(t_vector));
	program->player->steps = 0;
	program->player->balls = 0;
}

void 	ft_init_player(t_program *program)
{
	ft_new_sprite(program, "./img/trainer.xpm", 'P');
	ft_add_player(program);
}

void	ft_init_map(t_program *program)
{
	ft_new_sprite(program, "./img/grass.xpm", 'G');
	ft_new_sprite(program, "./img/rock.xpm", '1');
	ft_new_sprite(program, "./img/pokeball.xpm", 'C');
	ft_new_sprite(program, "./img/exit_closed.xpm", 'E');
	ft_init_player(program);
	count_balls(program);
}