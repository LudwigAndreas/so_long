#include "../includes/game.h"

t_list	*ft_get_hero(t_game *game, int i, int dir)
{
	t_list	*anim;
	char	*path;

	anim = NULL;
	path = NULL;
	path = ft_substr("resources/sprites/en/G/", 0, 23);
	if (i > 0)
		ft_memset(&path[21], ENEMIES[i % ft_strlen(ENEMIES)], 1);
	if (dir == N)
		anim = ft_load_north(game, path, 0);
	if (dir == W)
		anim = ft_load_west(game, path, 0);
	if (dir == S)
		anim = ft_load_south(game, path, 0);
	if (dir == E)
		anim = ft_load_east(game, path, 0);
	free(path);
	return (anim);
}

void	ft_load_enemies(t_game *game)
{
	t_entity	*enemy;
	int			i;

	i = 0;
	enemy = game->enemies;
	while (enemy)
	{
		enemy->sprite.up = ft_get_hero(game, i, N);
		enemy->sprite.st_up = enemy->sprite.up;
		enemy->sprite.down = ft_get_hero(game, i, S);
		enemy->sprite.st_down = enemy->sprite.down;
		enemy->sprite.right = ft_get_hero(game, i, E);
		enemy->sprite.st_right = enemy->sprite.right;
		enemy->sprite.left = ft_get_hero(game, i, W);
		enemy->sprite.st_left = enemy->sprite.left;
		enemy = enemy->next;
		i++;
	}
}

void	ft_put_stopped(t_game *game, t_entity *en)
{
	if (en->dir == N)
		mlx_put_image_to_window(game->mlx_id, game->window,
			en->sprite.st_up->content, en->pos.x * SIZE, en->pos.y * SIZE);
	if (en->dir == E || en->dir == ST)
		mlx_put_image_to_window(game->mlx_id, game->window,
			en->sprite.st_right->content, en->pos.x * SIZE, en->pos.y * SIZE);
	if (en->dir == S)
		mlx_put_image_to_window(game->mlx_id, game->window,
			en->sprite.st_down->content, en->pos.x * SIZE, en->pos.y * SIZE);
	if (en->dir == W)
		mlx_put_image_to_window(game->mlx_id, game->window,
			en->sprite.st_left->content, en->pos.x * SIZE, en->pos.y * SIZE);
}

void	ft_put_enemies(t_game *game)
{
	t_entity	*entity;

	entity = game->enemies;
	while (entity)
	{
		mlx_put_image_to_window(game->mlx_id, game->window,
			game->sprites.empty, entity->w_pos.x, entity->w_pos.y);
		if (entity->dir == E)
			ft_go_east(game, entity);
		if (entity->dir == N)
			ft_go_north(game, entity);
		if (entity->dir == W)
			ft_go_west(game, entity);
		if (entity->dir == S)
			ft_go_south(game, entity);
		if (entity->dir == ST)
			ft_put_stopped(game, entity);
		entity = entity->next;
	}
}
