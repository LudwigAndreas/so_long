#include "../includes/game.h"

void	ft_death(t_game *g)
{
	t_entity	*hero;

	hero = g->heroes;
	g->heroes->move = 0;
	if (g->sprites.hero_dying_r == NULL || g->sprites.hero_dying_l == NULL)
	{
		ft_putstr_fd("\nGAME OVER!\nLet's try again!\n\n", 1);
		close_game(g);
	}
	if (hero->prev_dir == E || hero->prev_dir == N) {
		mlx_put_image_to_window(g->mlx_id, g->window, \
        g->sprites.empty, g->heroes->w_pos.x, g->heroes->w_pos.y);
		mlx_put_image_to_window(g->mlx_id, g->window, \
        g->sprites.hero_dying_r->content, g->heroes->w_pos.x, g->heroes->w_pos.y);
		g->sprites.hero_dying_r = g->sprites.hero_dying_r->next;
	}
	else if (hero->prev_dir == W || hero->prev_dir == S) {
		mlx_put_image_to_window(g->mlx_id, g->window, \
        g->sprites.empty, g->heroes->w_pos.x, g->heroes->w_pos.y);
		mlx_put_image_to_window(g->mlx_id, g->window, \
        g->sprites.hero_dying_l->content, g->heroes->w_pos.x, g->heroes->w_pos.y);
		g->sprites.hero_dying_l = g->sprites.hero_dying_l->next;
	}
}

void	ft_check_redraw(t_game *game)
{
	if (!game->dead_ind)
		ft_redraw_hero(game);
	if (!game->dead_ind && (game->frames % 3))
		ft_redraw_enemies(game);
	if (!game->dead_ind && game->next_dir != ST)
		ft_update_en(game);
	if (game->next_dir && !game->dead_ind)
		ft_next_dir(game);
	if (game->dead_ind && game->frames % 7000 == 0)
		ft_death(game);
	if (game->params->coins == 0)
		ft_open_doors(game);
}

int	ft_update(t_game *game)
{
	int	x;
	int	y;

	game->frames++;
	ft_check_redraw(game);
	if (game->redraw)
	{
		ft_put_enemies(game);
		mlx_put_image_to_window(game->mlx_id, game->window,\
		game->sprites.logo, (game->width - LOGO_W) / 2, game->length - LOGO_L);
		ft_update_score(game);
		y = 0;
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				ft_render_map(game, x, y);
				x++;
			}
			y++;
		}
		game->redraw = 0;
	}
	return (0);
}

