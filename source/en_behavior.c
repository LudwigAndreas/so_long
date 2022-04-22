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

int	ft_get_en_dir(t_game *game, t_entity *enemy)
{
	int			dir;
	int			x;
	int 		y;
	t_entity	*hero;

	hero = game->heroes;
	ft_update_legal_act(game, enemy);
	dir = ft_check_legal(enemy);
//	ft_putnbr_fd(dir, 1);
	if (dir)
		return (dir);
	x = hero->pos.x - enemy->pos.x;
	y = hero->pos.y - enemy->pos.y;
	if (x * x >= y * y && x >= 0 && enemy->legal.E)
		return (E);
	if (x * x >= y * y && x < 0 && enemy->legal.W)
		return (W);
	if (y > 0 && enemy->legal.S)
		return (S);
	if (y <= 0 && enemy->legal.N)
		return (N);
//	if (x * x >= y * y && (enemy->legal.E || enemy->legal.W))
//	{
//		if (x >= 0 && enemy->legal.E)
//			return (E);
//		if (x < 0 && enemy->legal.W)
//			return (W);
//	}
//	else
//	{
//		if (y >= 0 && enemy->legal.S)
//			return (S);
//		if (y < 0 && enemy->legal.N)
//			return (N);
//	}
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
	if (dir == N)
		entity->pos.y--;
	if (dir == S)
		entity->pos.y++;
	if (dir == E)
		entity->pos.x++;
	if (dir == W)
		entity->pos.x--;
	entity->dir = dir;
	if (game->heroes->pos.x == entity->pos.x && game->heroes->pos.y == entity->pos.y)
	{
		game->dead_ind = 1;
		entity->pos = pos;
	}
}
