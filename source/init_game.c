/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:12:21 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:12:23 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"
#include <string.h>

/* Действия при нажатиях на кнопку */
int	key_hook(int key, t_game *game)
{
	if (key == ESC_KEY && !game->dead_ind)
	{
		ft_putendl_fd("Game was ended by player\n", 1);
		close_game(game);
	}
	if ((key == W_KEY || key == UP_KEY) && game->next_dir != N
		&& !game->dead_ind)
		next_direct(game, N);
	if ((key == A_KEY || key == LEFT_KEY) && game->next_dir != W
		&& !game->dead_ind)
		next_direct(game, W);
	if ((key == S_KEY || key == DOWN_KEY) && game->next_dir != S
		&& !game->dead_ind)
		next_direct(game, S);
	if ((key == D_KEY || key == RIGHT_KEY) && game->next_dir != E
		&& !game->dead_ind)
		next_direct(game, E);
	return (0);
}

/* Выход из игры с освобождением всей памяти */
int	close_game(t_game *game)
{
	int	i;

	free_sprites(game);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_clear_window(game->mlx_id, game->window);
	mlx_destroy_window(game->mlx_id, game->window);
	exit(0);
	return (0);
}

/*Функция инициирует игру*/
void	ft_new_game(t_game *game)
{
	game->sprites.hero = NULL;
	game->next_dir = 0;
	ft_add_entities(game);
	game->dead_ind = 0;
	game->g_rate = GAME_RATE;
	ft_load_hero(game);
	game->redraw = 1;
	ft_load_enemies(game);
	mlx_key_hook(game->window, key_hook, (void *) game);
	mlx_hook(game->window, 17, 0, close_game, (void *)game);
	mlx_loop_hook(game->mlx_id, ft_update, (void *)game);
	mlx_loop(game->mlx_id);
}

/* Функция запускает MLX */
void	init_game(t_params *params, char **map)
{
	t_game	game;

	game.mlx_id = mlx_init();
	if (!game.mlx_id)
		return ;
	game.params = params;
	game.length = params->length;
	game.width = params->width;
	game.all_coins = params->coins;
	game.map = map;
	game.window = mlx_new_window(game.mlx_id, params->width * SIZE + SCORE_W,
			params->length * SIZE + LOGO_L, "SO_LONG");
	game.frames = 1;
	game.moves = 0;
	game.width = params->width * SIZE;
	game.length = params->length * SIZE + LOGO_L;
	game.sprites = init_sprites(&game);
	game.heroes = NULL;
	game.enemies = NULL;
	game.all_coins = params->coins;
	ft_new_game(&game);
}
