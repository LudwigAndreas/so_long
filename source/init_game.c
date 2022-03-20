#include "../includes/map.h"
#include "../includes/game.h"

/* Действия при нажатиях на кнопку */
int	key_hook(int key, t_game *game)
{
	if (key == ESC_KEY)
		close_game(game);
	if (key == W_KEY)
		next_direct(game, N);
	if (key == A_KEY)
		next_direct(game, W);
	if (key == S_KEY)
		next_direct(game, S);
	if (key == D_KEY)
		next_direct(game, E);
	return (0);
}

/* Выход из игры с освобождением всей памяти */
int	close_game(t_game *game)
{
	//TODO освобождение памяти
	mlx_destroy_window(game->mlx_id, game->window);
	exit(0);
	return (0);
}

/*Функция инициирует игру*/
void	ft_new_game(t_game *game, t_params *params)
{
	game->frames = 1;
	game->all_coins = params->coins;
	game->dead_ind = 0;
	game->moves = 0;
	game->redraw = 1;
	game->heroes = NULL;
	game->enemies = NULL;
	game->g_rate = 24;
	game->width = params->width * SIZE;
	game->length = params->length * SIZE + LOGO_L;
	game->sprites = init_sprites(game);
	ft_add_entities(game);
	mlx_loop_hook(game->mlx_id, ft_update, (void *)game);
	mlx_key_hook(game->window, key_hook, (void *) game);
	mlx_hook(game->window, 17, 0, close_game, (void *)game);
	mlx_loop(game->mlx_id);
}

/*Функция запускает MLX*/
void	init_game(t_params *params, char **map)
{
	t_game game;

	game.params = params;
	game.length = params->length;
	game.width = params->width;
	game.all_coins = params->coins;
	game.map = ft_duplicate_matrix(map);
//	free(map);
	game.mlx_id = mlx_init();
	game.window = mlx_new_window(game.mlx_id, params->width * SIZE, params->length * SIZE + LOGO_L, "SO_LONG");
	ft_new_game(&game, params);
}