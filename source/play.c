#include "../includes/game.h"

void	next_direct(t_game *game, int dir)
{
	if (dir == N)
		ft_putendl_fd("W", 1);
	if (dir == W)
		ft_putendl_fd("A", 1);
	if (dir == S)
		ft_putendl_fd("S", 1);
	if (dir == E)
		ft_putendl_fd("D", 1);
//	ft_update_score(game)
	game->next_dir = dir;
}

void	ft_check_redraw(t_game *game)
{
	if (game->next_dir)
		ft_next_dir(game);
	if (!game->dead_ind)
		ft_redraw_hero(game);
//	if (game->dead_ind)
//		ft_death(game);
}

int	ft_update(t_game *game)
{
	int	x;
	int	y;

	game->frames++;
	ft_check_redraw(game);
	if (game->redraw)
	{
//		ft_put_enemies()
		mlx_put_image_to_window(game->mlx_id, game->window,\
		game->sprites.logo, (game->width - LOGO_W) / 2, game->length - LOGO_L);
//		ft_update_score(g);
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

