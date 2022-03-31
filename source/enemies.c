#include "../includes/game.h"

t_list	ft_get_enemy(t_game *game, int i, int dir)
{
	t_list	*anim;
	char	*path;
	int		j;

	j = 0;
	anim = NULL;
	path = NULL;
	path = ft_substr("resources/en/O/", 0, 15);
	if (i > 0)
		ft_memset(&path[13], ENEMIES[ft_strlen(ENEMIES) % 5], 1);
	if (dir == N)
		anim = ft_load_
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
		enemy = enemy->next;
		i++;
	}
}

void	ft_put_enemies(t_game *game)
{
	t_entity	*entity;

	entity = game->enemies;
	while (entity)
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x, entity->w_pos.y);
		if (entity->dir = )
	}
}

