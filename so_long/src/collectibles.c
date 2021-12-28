#include "so_long.h"

void	count_balls(t_program *program)
{
	int	i;

	i = -1;
	program->map->balls->amount = 0;
	while (program->map->map[++i])
	{
		if (program->map->map[i] == 'C')
			program->map->balls->amount++;
	}
}

void	ft_collect(t_program *program, int ball_pos)
{
	program->map->map[ball_pos] = '0';
	program->player->balls++;
	ft_init_sprite("./img/grass.xpm",
		program->player->player_pos->x, program->player->player_pos->y, program);
}