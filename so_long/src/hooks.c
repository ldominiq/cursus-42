#include "so_long.h"

int	ft_input(int key, t_program *program)
{
	if (!ft_search_key(key))
		return (0);
	ft_new_sprite(program, "./img/grass.xpm", '0');
	ft_init_sprite("./img/grass.xpm",
		program->player->player_pos->x, program->player->player_pos->y, program);
	if (key == KEY_RIGHT || key == KEY_D)
		ft_move_right(program);
	else if (key == KEY_LEFT || key == KEY_A)
		ft_move_left(program);
	else if (key == KEY_DOWN || key == KEY_S)
		ft_move_down(program);
	else if (key == KEY_UP || key == KEY_W)
		ft_move_up(program);
	else if (key == KEY_ESC)
		ft_close();
	return (0);
}
