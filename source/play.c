/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:12:49 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:12:50 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_death(t_game *g)
{
	t_entity	*hero;

	hero = g->heroes;
	g->heroes->move = 0;
	if (g->sprites.death_r == NULL || g->sprites.death_l == NULL)
	{
		ft_putstr_fd("\nGAME OVER!\nLet's try again!\n\n", 1);
		close_game(g);
	}
	if (hero->prev_dir == E || hero->prev_dir == N)
	{
		mlx_put_image_to_window(g->mlx_id, g->window, \
		g->sprites.empty, g->heroes->w_pos.x, g->heroes->w_pos.y);
		mlx_put_image_to_window(g->mlx_id, g->window, \
		g->sprites.death_r->content, g->heroes->w_pos.x, g->heroes->w_pos.y);
		g->sprites.death_r = g->sprites.death_r->next;
	}
	else
	{
		mlx_put_image_to_window(g->mlx_id, g->window, \
		g->sprites.empty, g->heroes->w_pos.x, g->heroes->w_pos.y);
		mlx_put_image_to_window(g->mlx_id, g->window, \
		g->sprites.death_l->content, g->heroes->w_pos.x, g->heroes->w_pos.y);
		g->sprites.death_l = g->sprites.death_l->next;
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
	if (!game->dead_ind && game->next_dir)
		ft_next_dir(game);
	if (!game->dead_ind && game->params->coins == 0)
		ft_open_doors(game);
	if (game->dead_ind && !(game->frames % 7000))
		ft_death(game);
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
		mlx_put_image_to_window(game->mlx_id, game->window, \
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
