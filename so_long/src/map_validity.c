/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_content(char **map)
{
	int	i;

	i = -1;
	while ((*map)[++i])
	{
		if ((*map)[i] != 'E' && (*map)[i] != 'P' &&
			(*map)[i] != 'C' && (*map)[i] != '1' &&
			(*map)[i] != '0' && (*map)[i] != '\n')
			return (0);
	}
	return (1);
}

int	check_map_validity(char **result)
{
	if (!check_map_content(result))
	{
		printf("Error\nThe map content isn't valid, must be (0, 1, C, E, P).\n");
		return (0);
	}
	if (!ft_strchr(*result, '0'))
		printf("Error\nThe map doesn't have ground (0).\n");
	else if (!ft_strchr(*result, '1'))
		printf("Error\nThe map doesn't have walls (1).\n");
	else if (!ft_strchr(*result, 'C'))
		printf("Error\nThe map doesn't have a collectible (C).\n");
	else if (!ft_strchr(*result, 'E'))
		printf("Error\nThe map doesn't have an exit (E).\n");
	else if (!ft_strchr(*result, 'P'))
		printf("Error\nThe map doesn't have a player (P).\n");
	else
		return (1);
	return (0);
}

int	check_map_border(char **map, int width)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(*map) - 1;
	while (++i < width)
	{
		if ((*map)[i] != '1' || (*map)[j--] != '1')
		{
			printf("Error\nThe map isn't surrounded by walls.\n");
			return (0);
		}
	}
	return (1);
}

void	check_map_walls_border(char **map, char *line, int width)
{
	int		i;

	i = -1;
	while (++i < width)
	{
		if ((line[0] != '1' || line[width - 1] != '1'))
		{
			printf("Error\nThe map isn't closed/surrounded by walls.\n");
			ft_free_ptr(map);
			exit(0);
		}
	}
}

void	check_map_shape(int width, char *line, char **save)
{
	int	last;

	last = ft_strlen(line) - 1;
	check_map_walls_border(save, line, width);
	if (line[last] != '\n')
		last += 1;
	if (width != last)
	{
		printf("Error\nThe map isn't rectangular.\n");
		ft_free_ptr(save);
		exit(0);
	}
}
