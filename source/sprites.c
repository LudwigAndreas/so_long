#include "../includes/game.h"

t_list	*load_death_l(t_game *game)
{
	t_list	*death;
	int		size;

	size = SIZE;
	death = NULL;
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_l/pl1.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_l/pl2.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_l/pl3.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_l/pl4.xpm", &size, &size)));
	game->sprites.hero_dying_l = death;
	return (death);
}

t_list	*load_death_r(t_game *game)
{
	t_list	*death;
	int		size;

	size = SIZE;
	death = NULL;
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_r/pl1.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_r/pl2.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_r/pl3.xpm", &size, &size)));
	ft_lstadd_back(&death, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/death_r/pl4.xpm", &size, &size)));
	game->sprites.hero_dying_r = death;
	return (death);
}

t_font  ft_load_font(t_game *game)
{
	int size;

	size = SIZE;
    game->sprites.font.one = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/1.xpm", &size, &size);
	game->sprites.font.two = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/2.xpm", &size, &size);
	game->sprites.font.three = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/3.xpm", &size, &size);
	game->sprites.font.four = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/4.xpm", &size, &size);
	game->sprites.font.five = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/5.xpm", &size, &size);
	game->sprites.font.six = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/6.xpm", &size, &size);
	game->sprites.font.seven = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/7.xpm", &size, &size);
	game->sprites.font.eight = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/8.xpm", &size, &size);
	game->sprites.font.nine = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/9.xpm", &size, &size);
	game->sprites.font.zero = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/digits/0.xpm", &size, &size);
	return (game->sprites.font);
}

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
		"resources/sprites/pl2/pl1.xpm", &size, &size);
	game->sprites.coin = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/coin.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/logo.xpm", &size, &size);
    game->sprites.score = mlx_xpm_file_to_image(game->mlx_id, \
    	"resources/sprites/score.xpm", &size, &size);
	game->sprites.open_ex = mlx_xpm_file_to_image(game->mlx_id, \
    	"resources/sprites/opened_door.xpm", &size, &size);
    game->sprites.hero_dying_r = load_death_r(game);
	game->sprites.hero_dying_l = load_death_l(game);
	game->sprites.font = ft_load_font(game);
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
