/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
