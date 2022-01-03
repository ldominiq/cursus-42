/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(void)
{
	exit(0);
}

int	ft_new_window(int width, int height, char **map)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (0);
	ft_init(program);
	program->window.size.x = width;
	program->window.size.y = height;
	program->map->map = *map;
	program->mlx = mlx_init();
	program->window.reference = mlx_new_window(program->mlx,
			program->window.size.x * SPRITE_SIZE,
			program->window.size.y * SPRITE_SIZE, "PokeLong");
	ft_init_map(program);
	mlx_hook(program->window.reference, 17, 0, ft_close, 0);
	mlx_key_hook(program->window.reference, *ft_input, program);
	mlx_loop(program->mlx);
	ft_free(program);
	return (0);
}
