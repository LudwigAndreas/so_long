#include "../includes/game.h"

int ft_check_legal(t_entity *enemy)
{
	if (enemy->dir == N && !(enemy->legal.E && enemy->legal.W))
		return (N);
	if (enemy->dir == S && !(enemy->legal.E && enemy->legal.W))
		return (S);
	if (enemy->dir == W && !(enemy->legal.N && enemy->legal.S))
		return (W);
	if (enemy->dir == E && !(enemy->legal.N && enemy->legal.S))
		return (E);
	else
		return (0);
}

int	ft_get_en_dir(t_game *game, t_entity *enemy)
{
	int			dir;
	int			x;
	int 		y;
	t_entity	*hero;
//	ft_putendl_fd("got next dir\n", 1);

	hero = game->heroes;
	ft_update_legal_act(game, enemy);
	dir = ft_check_legal(enemy);
	//Если вернулось 0, математически выщитываем наилучший возможный путь к игроку
	if (dir)
		return (dir);
	x = hero->pos.x - enemy->pos.x;
	y = hero->pos.y - enemy->pos.y;
	//Приоритетно сокращаем дистанцию по стандарту
//	if ()
	if (x * x >= y * y)
	{
		ft_putendl_fd("EW", 1);
		if (x >= 0 && enemy->legal.E)
			return (E);
		if (x < 0 && enemy->legal.W)
			return (W);
	}
	else
	{
		ft_putendl_fd("SN", 1);
		if (y >= 0 && enemy->legal.S)
			return (S);
		if (y < 0 && enemy->legal.N)
			return (N);
	}

//	ft_putendl_fd("ST", 1);
	return (ST);
}

void	ft_update_en(t_game *game)
{
	t_entity	*enemy;
	int			dir;

	enemy = game->enemies;
	while (enemy && !enemy->move)
	{
//		ft_putendl_fd("enemy:\n", 1);
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
	if (game->map[entity->pos.y][entity->pos.x] == 'P')
	{
		game->dead_ind = 1;
		entity->pos = pos;
	}
	(void )game;
}
