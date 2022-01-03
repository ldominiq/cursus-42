#include "so_long.h"

void	ft_free(t_program *program)
{
	free(program->map->balls);
	program->map->balls = NULL;
	free(program->map);
	program->map = NULL;
	free(program->player->player_pos);
	program->player->player_pos = NULL;
	free(program->player);
	program->player = NULL;
	free(program);
	program = NULL;
}

void	ft_free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}