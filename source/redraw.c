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
//		ft_redraw_items(game, enemy);
		enemy = enemy->next;
	}
	ft_put_enemies(game);
}