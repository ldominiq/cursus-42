#include "so_long.h"

void	ft_move_right(t_program *program)
{
	int	current_pos;
	int	next_pos;
	int	next_sprite;

	current_pos = ft_strchr_pos(program->map->map, 'P');
	next_pos = current_pos + 1;
	next_sprite = program->map->map[next_pos];
	if (next_sprite != '1')
	{
		program->map->map[current_pos] = '0';
		program->map->map[next_pos] = 'P';
		program->player->player_pos->x += SPRITE_SIZE;
		ft_add_player(program);
	}
	ft_init_sprite("./img/trainer.xpm", program->player->player_pos->x,
		program->player->player_pos->y, program);
}

void	ft_move_left(t_program *program)
{
	int	current_pos;
	int	next_pos;
	int	next_sprite;

	current_pos = ft_strchr_pos(program->map->map, 'P');
	next_pos = current_pos - 1;
	next_sprite = program->map->map[next_pos];
	if (next_sprite != '1')
	{
		program->map->map[current_pos] = '0';
		program->map->map[next_pos] = 'P';
		program->player->player_pos->x -= SPRITE_SIZE;
		ft_add_player(program);
	}
	ft_init_sprite("./img/trainer.xpm", program->player->player_pos->x,
		program->player->player_pos->y, program);
}

void	ft_move_up(t_program *program)
{
	int	current_pos;
	int	next_pos;
	int	next_sprite;

	current_pos = ft_strchr_pos(program->map->map, 'P');
	next_pos = current_pos - (program->window.size.x + 1);
	next_sprite = program->map->map[next_pos];
	if (next_sprite != '1')
	{
		program->map->map[current_pos] = '0';
		program->map->map[next_pos] = 'P';
		program->player->player_pos->y -= SPRITE_SIZE;
		ft_add_player(program);
	}
	ft_init_sprite("./img/trainer.xpm", program->player->player_pos->x,
		program->player->player_pos->y, program);
}

void	ft_move_down(t_program *program)
{
	int	current_pos;
	int	next_pos;
	int	next_sprite;

	current_pos = ft_strchr_pos(program->map->map, 'P');
	next_pos = current_pos + (program->window.size.x + 1);
	next_sprite = program->map->map[next_pos];
	if (next_sprite != '1')
	{
		program->map->map[current_pos] = '0';
		program->map->map[next_pos] = 'P';
		program->player->player_pos->y += SPRITE_SIZE;
		ft_add_player(program);
	}
	ft_init_sprite("./img/trainer.xpm", program->player->player_pos->x,
		program->player->player_pos->y, program);
}