/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:34 by ldominiq          #+#    #+#             */
/*   Updated: 2021/01/03 22:01:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_errors(int argc)
{
	if (argc > 2)
	{
		printf("Error\nToo many arguments.\n");
		ft_close();
		return (1);
	}
	else if (argc == 1)
	{
		printf("Error\nPlease enter a map: ./so_long path/map.ber\n");
		ft_close();
		return (1);
	}
	return (0);
}
