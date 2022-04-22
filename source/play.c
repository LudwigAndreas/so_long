#include "../includes/game.h"

void	ft_death(t_game *game)
{
	t_entity	*hero;

	hero = game->heroes;
	game->heroes->move = 0;
	if (game->sprites.hero_dying_r == NULL || game->sprites.hero_dying_l == NULL)
	{
		ft_putstr_fd("\nGAME OVER!\nLet's try again!\n\n", 1);
		close_game(game);
	}
	if (hero->prev_dir == E || hero->prev_dir == N) {
		mlx_put_image_to_window(game->mlx_id, game->window, \
        game->sprites.empty, game->heroes->w_pos.x, game->heroes->w_pos.y);
		mlx_put_image_to_window(game->mlx_id, game->window, \
        game->sprites.hero_dying_r->content, game->heroes->w_pos.x, game->heroes->w_pos.y);
		game->sprites.hero_dying_r = game->sprites.hero_dying_r->next;
	}
	else if (hero->prev_dir == W || hero->prev_dir == S) {
		mlx_put_image_to_window(game->mlx_id, game->window, \
        game->sprites.empty, game->heroes->w_pos.x, game->heroes->w_pos.y);
		mlx_put_image_to_window(game->mlx_id, game->window, \
        game->sprites.hero_dying_l->content, game->heroes->w_pos.x, game->heroes->w_pos.y);
		game->sprites.hero_dying_l = game->sprites.hero_dying_l->next;
	}
}

void	ft_check_redraw(t_game *game)
{
	if (!game->dead_ind)
		ft_redraw_hero(game);
//	ft_putendl_fd("1", 1);
	if (!game->dead_ind && !(game->frames % 3))
		ft_redraw_enemies(game);
//	ft_putendl_fd("2", 1);
	if ((game->heroes->dir != ST && game->frames != 1) && !game->dead_ind)
		ft_update_en(game);
//	ft_putendl_fd("3", 1);
	if (game->next_dir && !game->dead_ind)
		ft_next_dir(game);
//	ft_putendl_fd("4", 1);
	if (game->dead_ind && game->frames % 7000 == 0)
		ft_death(game);
	if (game->params->coins == 0)
		ft_open_doors(game);
//	ft_putendl_fd("5", 1);
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

