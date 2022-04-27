#include "../includes/game.h"

int	ft_check_legal(t_entity *en)
{
	if (en->dir == N && en->legal.N && !en->legal.E && !en->legal.W)
		return (N);
	if (en->dir == S && en->legal.S && !en->legal.E && !en->legal.W)
		return (S);
	if (en->dir == W && en->legal.W && !en->legal.N && !en->legal.S)
		return (W);
	if (en->dir == E && en->legal.E && !en->legal.N && !en->legal.S)
		return (E);
	return (0);
}

int	ft_get_euclidean(const int *posi)
{
	int	i;
	int	min;
	int	j;

	i = 0;
	j = -1;
	min = -1;
	while (i != 4)
	{
		if (posi[i] >= 0 && (min == -1 || posi[i] < min))
		{
			min = posi[i];
			j = i;
		}
		i++;
	}
	if (j == 0)
		return (E);
	if (j == 1)
		return (W);
	if (j == 2)
		return (S);
	if (j == 3)
		return (N);
	return (ST);
}

int	ft_get_en_dir(t_game *game, t_entity *en)
{
	int			posi[4];
	t_entity	*hero;

	hero = game->heroes;
	if (en->legal.E)
		posi[0] = evclid(ft_new_pos(en->pos.x + 1, en->pos.y),
				ft_new_pos(hero->pos.x, hero->pos.y));
	else
		posi[0] = -1;
	if (en->legal.W)
		posi[1] = evclid(ft_new_pos(en->pos.x - 1, en->pos.y),
				ft_new_pos(hero->pos.x, hero->pos.y));
	else
		posi[1] = -1;
	if (en->legal.S)
		posi[2] = evclid(ft_new_pos(en->pos.x, en->pos.y + 1),
				ft_new_pos(hero->pos.x, hero->pos.y));
	else
		posi[2] = -1;
	if (en->legal.N)
		posi[3] = evclid(ft_new_pos(en->pos.x, en->pos.y - 1),
				ft_new_pos(hero->pos.x, hero->pos.y));
	else
		posi[3] = -1;
	return (ft_get_euclidean(posi));
}

void	ft_update_en(t_game *game)
{
	t_entity	*enemy;
	int			dir;

	enemy = game->enemies;
	while (enemy && !enemy->move)
	{
		ft_update_legal_act(game, enemy);
		dir = ft_check_legal(enemy);
		if (!dir)
			dir = ft_get_en_dir(game, enemy);
		enemy->move = 1;
		ft_move_en(dir, enemy, game);
		enemy = enemy->next;
	}
}

void	ft_move_en(int dir, t_entity *entity, t_game *g)
{
	t_pos	pos;

	pos = ft_new_pos(entity->pos.x, entity->pos.y);
	ft_memset(&g->map[entity->pos.y][entity->pos.x], \
		'0', g->map[entity->pos.y][entity->pos.x] == 'G');
	if (g->heroes->pos.x == entity->pos.x && g->heroes->pos.y == entity->pos.y)
	{
		g->dead_ind = 1;
		entity->pos = pos;
	}
	if (dir == N)
		entity->pos.y--;
	if (dir == S)
		entity->pos.y++;
	if (dir == E)
		entity->pos.x++;
	if (dir == W)
		entity->pos.x--;
	if (g->heroes->pos.x == entity->pos.x && g->heroes->pos.y == entity->pos.y)
	{
		g->dead_ind = 1;
		entity->pos = pos;
	}
	entity->dir = dir;
}
