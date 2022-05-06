/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:13:26 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:13:28 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_pos	ft_new_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_id, game->sprites.logo);
	mlx_destroy_image(game->mlx_id, game->sprites.score);
	mlx_destroy_image(game->mlx_id, game->sprites.wall);
	mlx_destroy_image(game->mlx_id, game->sprites.exit);
	mlx_destroy_image(game->mlx_id, game->sprites.open_ex);
	mlx_destroy_image(game->mlx_id, game->sprites.empty);
	mlx_destroy_image(game->mlx_id, game->sprites.coin);
}
