#include "so_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
//int	ft_input(int key, void *param)
int	ft_input(int key)
{
	//t_program *program = (t_program *)param;

	// mlx function that clears the window
	//mlx_clear_window(program->mlx, program->window.reference);

	// move in a direction based on the key
	if (key == 124 || key == 2)
		printf("Key pressed -> %d\n", key);
	else if (key == 123 || key == 0)
		printf("Key pressed -> %d\n", key);
	else if (key == 125 || key == 1)
		printf("Key pressed -> %d\n", key);
	else if (key == 126 || key == 13)
		printf("Key pressed -> %d\n", key);
	else if (key == 53)
		ft_close();

	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
}
