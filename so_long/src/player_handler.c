/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_add_player(t_program *program)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (program->window.size.y > ++y)
	{
		while ((program->map->map)[++i] && program->window.size.x > ++x)
		{
			if ((program->map->map)[i] == 'P')
			{
				program->player->player_pos->x = x * SPRITE_SIZE;
				program->player->player_pos->y = y * SPRITE_SIZE;
			}
		}
		x = -1;
	}
}
