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
	if (hero->pos.x * SIZE == hero->w_pos.x && hero->pos.y * SIZE == hero->w_pos.y) {
		hero->move = 0;
	}
	ft_put_hero(game);
}