#include "../includes/game.h"

int ft_check_legal(t_entity *enemy)
{
	if (enemy->dir == N && !(enemy->legal.E || enemy->legal.W)
			&& enemy->legal.N)
		return (N);
	if (enemy->dir == S && !(enemy->legal.E || enemy->legal.W)
			&& enemy->legal.S)
		return (S);
	if (enemy->dir == W && !(enemy->legal.N || enemy->legal.S)
			&& enemy->legal.W)
		return (W);
	if (enemy->dir == E && !(enemy->legal.N || enemy->legal.S)
			&& enemy->legal.E)
		return (E);
	return (0);
}

int	evclid(t_pos p1, t_pos p2)
{
	return (((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

int	ft_get_en_dir(t_game *game, t_entity *en)
{
	int			dir;
	int			posi[4];
	int			i;
	int 		min;
	t_entity	*hero;

	hero = game->heroes;
	ft_update_legal_act(game, en);
	dir = ft_check_legal(en);
	if (dir)
		return (dir);
	posi[0] = evclid(ft_new_pos(en->pos.x + 1, en->pos.y),
					 ft_new_pos(hero->pos.x, hero->pos.y)) * en->legal.E;
	posi[1] = evclid(ft_new_pos(en->pos.x - 1, en->pos.y),
					 ft_new_pos(hero->pos.x, hero->pos.y)) * en->legal.W;
	posi[2] = evclid(ft_new_pos(en->pos.x, en->pos.y + 1),
					 ft_new_pos(hero->pos.x, hero->pos.y)) * en->legal.S;
	posi[3] = evclid(ft_new_pos(en->pos.x, en->pos.y - 1),
					 ft_new_pos(hero->pos.x, hero->pos.y)) * en->legal.N;
	i = 0;
	dir = -1;
	while (i != 4)
	{
		if (posi[i] > 0 && (dir == -1 || posi[i] < min))
		{
			min = posi[i];
			dir = i;
		}
		i++;
	}
	if (dir == 0)
		return (E);
	if (dir == 1)
		return (W);
	if (dir == 2)
		return (S);
	if (dir == 3)
		return (N);
	return (ST);
}

void	ft_update_en(t_game *game)
{
	t_entity	*enemy;
	int			dir;

	enemy = game->enemies;
	while (enemy && !enemy->move)
	{
		dir = ft_get_en_dir(game, enemy);
		enemy->move = 1;
		ft_move_en(dir, enemy, game);
		enemy = enemy->next;
	}
}

void	ft_move_en(int dir, t_entity *entity, t_game *game)
{
	t_pos pos;

	pos = ft_new_pos(entity->pos.x, entity->pos.y);
	ft_memset(&game->map[entity->pos.y][entity->pos.x], \
		'0', game->map[entity->pos.y][entity->pos.x] == 'G');
	if (game->heroes->pos.x == entity->pos.x && game->heroes->pos.y == entity->pos.y)
	{
		game->dead_ind = 1;
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
	if (game->heroes->pos.x == entity->pos.x && game->heroes->pos.y == entity->pos.y)
	{
		game->dead_ind = 1;
		entity->pos = pos;
	}
	entity->dir = dir;
}
