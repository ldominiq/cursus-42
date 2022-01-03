#include "so_long.h"

int	ft_strchr_pos(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_escape(t_program *program, int next_sprite)
{
	if (next_sprite == 'E' && (program->map->balls->amount == program->player->balls))
	{
		mlx_clear_window(program->mlx, program->window.reference);
		printf("You won ! GG\n");
		ft_close();
	}
}