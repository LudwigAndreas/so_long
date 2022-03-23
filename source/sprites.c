#include "../includes/game.h"

//TODO load death
t_list	*load_death(t_game *game)
{
	t_list	*death;
	int		size;
	t_list	*new;

	size = SIZE;
	death = NULL;
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/death/pl_death1.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/death/pl_death2.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/death/pl_death3.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/death/pl_death4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/death/pl_death5.xpm", &size, &size));
	ft_lstadd_back(&death, new);
	new->next = death;
	return (death);
}

//t_font  *ft_load_font(t_game *game)
//{
//    t_font  *font;
//
//    font = game->sprites.font;
//    font->one = mlx_xpm_file_to_image(game->mlx_id, \
//	"resources/sprites/sprites_xpm/bg.xpm", &size, &size);
//}

t_sprites	init_sprites(t_game *game)
{
	int size;

	size = SIZE;
	game->sprites.empty = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/bg.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/wall.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/closed_door.xpm", &size, &size);
	game->sprites.hero = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/pl.xpm", &size, &size);
	game->sprites.coin = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/coin.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/logo.xpm", &size, &size);
    game->sprites.score = mlx_xpm_file_to_image(game->mlx_id, \
    	"resources/sprites/score.xpm", &size, &size);
	game->sprites.open_ex = mlx_xpm_file_to_image(game->mlx_id, \
    	"resources/sprites/opened_door.xpm", &size, &size);
    game->sprites.hero_dying = load_death(game);
//	game->sprites.font = ft_load_font(game);
	return (game->sprites);
}

void	ft_render_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.wall, \
			x * SIZE, y * SIZE);
	}
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.exit, \
			x * SIZE, y * SIZE);
	}
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.coin, \
			x * SIZE, y * SIZE);
	}
	if (game->map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, \
			x * SIZE, y * SIZE);
	}
}


//TODO render bg 1 block around down map
//void	ft_render_around_map(t_game *game)
//{
//	int x;
//	int y;
//
//	while ()
//}