/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:20:21 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/21 14:51:33 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		program->player->player_pos->x, program->player->player_pos->y,
		program);
	if (program->player->balls == program->map->balls->amount)
	{
		ft_new_sprite(program, "./img/grass.xpm", 'E');
		ft_new_sprite(program, "./img/exit_open.xpm", 'E');
	}
}
