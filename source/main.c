/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:12:38 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:12:39 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_params	params;

	map = map_checker(argc, argv, &params);
	init_game(&params, map);
	return (0);
}
