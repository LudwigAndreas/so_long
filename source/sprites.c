#include "../includes/game.h"

//TODO load death
t_list	*load_death(t_game *game)
{
	t_list	*death;
	int		size;
	t_list	*new;

	size = SIZE;
	death = NULL;
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, "resources/sprites/sprites_xpm/hero_death/g_hero_death1.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, "resources/sprites/sprites_xpm/hero_death/g_hero_death2.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, "resources/sprites/sprites_xpm/hero_death/g_hero_death3.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, "resources/sprites/sprites_xpm/hero_death/g_hero_death4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, "resources/sprites/sprites_xpm/hero_death/g_hero_death5.xpm", &size, &size));
	ft_lstadd_back(&death, new);
	new->next = death;
	return (death);
}

t_sprites	init_sprites(t_game *game)
{
	int size;

	size = SIZE;
	game->sprites.empty = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/bg.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/wall.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/closed_door.xpm", &size, &size);
	game->sprites.hero = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/g_hero.xpm", &size, &size);
	game->sprites.coin = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/coin.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->mlx_id, \
	"resources/sprites/sprites_xpm/logo.xpm", &size, &size);
	game->sprites.hero_dying_r = load_death(game);
	//game->sprites->font
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


//TODO render bg 1 block around map
//void	ft_render_around_map(t_game *game)
//{
//	int x;
//	int y;
//
//	while ()
//}