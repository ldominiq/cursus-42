#include "so_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, t_program *program)
{
	ft_new_sprite(program, "./img/grass.xpm", '0');
	ft_init_sprite("./img/grass.xpm",
		program->player->player_pos->x, program->player->player_pos->y, program);
	// move in a direction based on the key
	if (key == 124 || key == 2)
		ft_move_right(program);
	else if (key == 123 || key == 0)
		ft_move_left(program);
	else if (key == 125 || key == 1)
		ft_move_down(program);
	else if (key == 126 || key == 13)
		ft_move_up(program);
	else if (key == 53)
		ft_close();
	printf("Key pressed -> %d\n", key);
	return (0);
}
