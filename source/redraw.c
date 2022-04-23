#include "../includes/game.h"

void	ft_redraw_hero(t_game *game)
{
	t_entity	*hero;

	hero = game->heroes;
	if (hero->pos.x * SIZE > hero->w_pos.x && hero->move)
		hero->w_pos.x += 3;
	if (hero->pos.x * SIZE < hero->w_pos.x && hero->move)
		hero->w_pos.x -= 3;
	if (hero->pos.y * SIZE > hero->w_pos.y && hero->move)
		hero->w_pos.y += 3;
	if (hero->pos.y * SIZE < hero->w_pos.y && hero->move)
		hero->w_pos.y -= 3;
	if (hero->pos.x * SIZE == hero->w_pos.x
		&& hero->pos.y * SIZE == hero->w_pos.y)
		hero->move = 0;
	ft_put_hero(game);
}

void	ft_redraw_items(t_game *game, t_entity *entity)
{
	if (entity->dir == N && game->map[entity->pos.y + 1][entity->pos.x] == 'C')
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.coin,
								entity->pos.x * SIZE, (entity->pos.y + 1) * SIZE);
	if (entity->dir == S && game->map[entity->pos.y - 1][entity->pos.x] == 'C')
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.coin,
								entity->pos.x * SIZE, (entity->pos.y - 1) * SIZE);
	if (entity->dir == W && game->map[entity->pos.y][entity->pos.x + 1] == 'C')
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.coin,
								(entity->pos.x + 1) * SIZE, entity->pos.y * SIZE);
	if (entity->dir == E && game->map[entity->pos.y][entity->pos.x - 1] == 'C')
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.coin,
								(entity->pos.x - 1) * SIZE, entity->pos.y * SIZE);
}

void	ft_redraw_enemies(t_game *game)
{
	t_entity	*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy->pos.x * SIZE > enemy->w_pos.x && enemy->move)
			enemy->w_pos.x += 3;
		if (enemy->pos.x * SIZE < enemy->w_pos.x && enemy->move)
			enemy->w_pos.x -= 3;
		if (enemy->pos.y * SIZE > enemy->w_pos.y && enemy->move)
			enemy->w_pos.y += 3;
		if (enemy->pos.y * SIZE < enemy->w_pos.y && enemy->move)
			enemy->w_pos.y -= 3;
		if (enemy->pos.x * SIZE == enemy->w_pos.x
			&& enemy->pos.y * SIZE == enemy->w_pos.y)
		{
			enemy->move = 0;
		}
		ft_redraw_items(game, enemy);
		enemy = enemy->next;
	}
	ft_put_enemies(game);
}