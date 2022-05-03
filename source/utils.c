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

void	ft_free_en_list(t_game *game)
{
	t_entity	*temp;

	free(game->heroes);
	while (game->enemies)
	{
		temp = game->enemies;
		game->enemies = game->enemies->next;
		free(temp);
	}
}

void	ft_clear_mlx_anim(t_game *game, t_list *anim)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (i != 5)
	{
		temp = anim;
		if (anim)
			anim = anim->next;
		if (game && temp != NULL)
			mlx_destroy_image(game->mlx_id, temp->content);
		free(temp);
		temp = NULL;
		i++;
	}
}

void	free_entity(t_game *game )
{
	t_entity	*entity;

	ft_clear_mlx_anim(game, game->sprites.death_st_l);
	ft_clear_mlx_anim(game, game->sprites.death_st_r);
	ft_clear_mlx_anim(game, game->heroes->sprite.st_up);
	ft_clear_mlx_anim(game, game->heroes->sprite.st_left);
	ft_clear_mlx_anim(game, game->heroes->sprite.st_right);
	ft_clear_mlx_anim(game, game->heroes->sprite.st_down);
	entity = game->enemies;
	while (entity)
	{
		ft_clear_mlx_anim(game, entity->sprite.st_down);
		ft_clear_mlx_anim(game, entity->sprite.st_up);
		ft_clear_mlx_anim(game, entity->sprite.st_left);
		ft_clear_mlx_anim(game, entity->sprite.st_right);
		entity = entity->next;
	}
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
	free_entity(game);
	ft_free_en_list(game);
}
