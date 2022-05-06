/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:46:39 by lsherry           #+#    #+#             */
/*   Updated: 2022/05/06 14:46:40 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_move(t_entity *entity, t_game *game)
{
	t_pos	pos;

	if (entity->dir == N && ft_is_mov_legal(entity, entity->dir))
		pos = ft_new_pos(entity->pos.x, entity->pos.y - 1);
	else if (entity->dir == W && ft_is_mov_legal(entity, entity->dir))
		pos = ft_new_pos(entity->pos.x - 1, entity->pos.y);
	else if (entity->dir == S && ft_is_mov_legal(entity, entity->dir))
		pos = ft_new_pos(entity->pos.x, entity->pos.y + 1);
	else if (entity->dir == E && ft_is_mov_legal(entity, entity->dir))
		pos = ft_new_pos(entity->pos.x + 1, entity->pos.y);
	else
		pos = ft_new_pos(0, 0);
	ft_memset(&game->map[entity->pos.y][entity->pos.x], \
		'0', game->map[entity->pos.y][entity->pos.x] == 'P');
	if (game->map[pos.y][pos.x] == 'C')
	{
		game->map[pos.y][pos.x] = '0';
		game->params->coins--;
	}
	if (pos.x && pos.y)
		ft_door_checker(game, entity, pos);
}

void	ft_next_dir(t_game *game)
{
	t_entity	*hero;

	hero = game->heroes;
	if (!hero->move)
	{
		ft_update_legal_act(game, hero);
		if (game->next_dir && ft_is_mov_legal(hero, game->next_dir))
		{
			hero->prev_dir = hero->dir;
			hero->dir = game->next_dir;
		}
		else
			hero->dir = ST;
		ft_move(hero, game);
		hero->move = 1;
	}
}

int	ft_is_there_en(t_game *game, int x, int y)
{
	t_entity	*en2;

	en2 = game->enemies;
	while (en2)
	{
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		en2 = en2->next;
	}
	return (1);
}

void	ft_update_legal_act(t_game *game, t_entity *en)
{
	char	*s;
	int		i;

	i = 2;
	if (en == game->heroes)
		i = 1;
	s = ft_substr("1E", 0, i);
	en->legal.n = (!ft_strchr(s, game->map[en->pos.y - 1][en->pos.x]));
	en->legal.s = (!ft_strchr(s, game->map[en->pos.y + 1][en->pos.x]));
	en->legal.e = (!ft_strchr(s, game->map[en->pos.y][en->pos.x + 1]));
	en->legal.w = (!ft_strchr(s, game->map[en->pos.y][en->pos.x - 1]));
	free(s);
	if (game->heroes == en)
		return ;
	en->legal.n *= ft_is_there_en(game, en->pos.x, en->pos.y - 1);
	en->legal.s *= ft_is_there_en(game, en->pos.x, en->pos.y + 1);
	en->legal.e *= ft_is_there_en(game, en->pos.x + 1, en->pos.y);
	en->legal.w *= ft_is_there_en(game, en->pos.x - 1, en->pos.y);
}

int	ft_is_mov_legal(t_entity *entity, int dir)
{
	if (dir == N && entity->legal.n)
		return (1);
	if (dir == W && entity->legal.w)
		return (1);
	if (dir == S && entity->legal.s)
		return (1);
	if (dir == E && entity->legal.e)
		return (1);
	if (dir == ST)
		return (1);
	return (0);
}
