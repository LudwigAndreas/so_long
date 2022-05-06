/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:11:41 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:11:43 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_entity	*ft_create_en(t_pos pos)
{
	t_entity	*entity;

	entity = (t_entity *) malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->pos = pos;
	entity->w_pos = ft_new_pos(pos.x * SIZE, pos.y * SIZE);
	entity->dir = 0;
	entity->move = 0;
	entity->next = NULL;
	return (entity);
}

void	ft_en_add_back(t_entity **lst, t_entity *new)
{
	t_entity	*elem;

	if (*lst)
	{
		elem = *lst;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		*lst = new;
}

void	ft_add_entities(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->heroes = ft_create_en(ft_new_pos(x, y));
			if (game->map[y][x] == 'G')
				ft_en_add_back(&game->enemies, ft_create_en(ft_new_pos(x, y)));
			x++;
		}
		y++;
	}
}

void	ft_open_doors(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_id, game->window,
					game->sprites.open_ex, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	ft_door_checker(t_game *game, t_entity *entity, t_pos new)
{
	if (game->map[new.y][new.x] == 'E' && game->params->coins == 0)
	{
		printf("\nYou win!\nTotal number of moves: %d\nCollected coins: %d\n",
			game->moves, game->all_coins);
		close_game(game);
	}
	if (game->map[new.y][new.x] == 'E')
	{
		entity->move = 0;
		entity->dir = ST;
		return ;
	}
	entity->move = 1;
	entity->pos = new;
}
