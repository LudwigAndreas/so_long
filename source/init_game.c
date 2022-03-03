#include "../includes/map.h"
#include "../includes/game.h"
#include <mlx.h>
#include "stdio.h"

/*Функция инициирует игру*/
void	ft_new_game(t_game *game, char **map, t_params *params)
{

}

/*Функция запускает MLX*/
void	init_game(t_params *params, char **map)
{
	t_game game;

	game.params = params;
	game.length = params->length;
	game.width = params->width;
	game.all_coins = params->coins;
	game.map = ft_matrix_dup(map);
	game.mlx_id = mlx_init();
	game.window = mlx_new_window(game.mlx_id,params->length * SIZE, params->width * SIZE + LOGO_SIZE, "Pacman");
	ft_new_game(&game, map, params);
}