#include "../includes/game.h"

t_list	*ft_get_enemy(t_game *game, int i, int dir)
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
		enemy->sprite.up = ft_get_enemy(game, i, N);
		enemy->sprite.st_up = enemy->sprite.up;
		enemy->sprite.down = ft_get_enemy(game, i, S);
		enemy->sprite.st_down = enemy->sprite.down;
		enemy->sprite.right = ft_get_enemy(game, i, E);
		enemy->sprite.st_right = enemy->sprite.right;
		enemy->sprite.left = ft_get_enemy(game, i, W);
		enemy->sprite.st_left = enemy->sprite.left;
		enemy = enemy->next;
		i++;
	}
}

void	ft_put_stopped(t_game *game, t_entity *entity)
{
	if (entity->dir == N)
		mlx_put_image_to_window(game->mlx_id, game->window,
			entity->sprite.st_up->content, entity->pos.x * SIZE, entity->pos.y * SIZE);
	if (entity->dir == E || entity->dir == ST)
		mlx_put_image_to_window(game->mlx_id, game->window,
			entity->sprite.st_right->content, entity->pos.x * SIZE, entity->pos.y * SIZE);
	if (entity->dir == S)
		mlx_put_image_to_window(game->mlx_id, game->window,
			entity->sprite.st_down->content, entity->pos.x * SIZE, entity->pos.y * SIZE);
	if (entity->dir == W)
		mlx_put_image_to_window(game->mlx_id, game->window,
			entity->sprite.st_left->content, entity->pos.x * SIZE, entity->pos.y * SIZE);
}

void	ft_put_enemies(t_game *game)
{
	t_entity	*entity;

	entity = game->enemies;
	while (entity)
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x, entity->w_pos.y);
		if (entity->dir == E && entity->move)
			ft_go_east(game, entity);
		if (entity->dir == N && entity->move)
			ft_go_north(game, entity);
		if (entity->dir == W && entity->move)
			ft_go_west(game, entity);
		if (entity->dir == S && entity->move)
			ft_go_south(game, entity);
		if (entity->move == 0)
			ft_put_stopped(game, entity);
		entity = entity->next;
	}
}
