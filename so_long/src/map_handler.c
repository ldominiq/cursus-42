/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (next_sprite == 'E' && (
			program->map->balls->amount == program->player->balls))
	{
		mlx_clear_window(program->mlx, program->window.reference);
		printf("You won ! GG\n");
		ft_close();
	}
}
