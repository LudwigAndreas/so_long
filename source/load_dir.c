/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:06:11 by lsherry           #+#    #+#             */
/*   Updated: 2022/03/23 17:06:25 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_list	*ft_load_south(t_game *game)
{
	t_list	*run;
	int		size;
	t_list	*new;

	size = SIZE;
	run = NULL;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/down/pl_down1.xpm", &size, &size)));
	game->heroes->sprite.st_down = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/down/pl_down2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/down/pl_down3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/down/pl_down4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/down/pl_down5.xpm", &size, &size));
	ft_lstadd_back(&run, new);
	new->next = run;
	game->heroes->sprite.down = run;
	return (run);
}

t_list	*ft_load_west(t_game *game)
{
	t_list	*run;
	int		size;
	t_list	*new;

	size = SIZE;
	run = NULL;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/left/pl_left1.xpm", &size, &size)));
	game->heroes->sprite.st_left = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/left/pl_left2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/left/pl_left3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/left/pl_left4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/left/pl_left5.xpm", &size, &size));
	ft_lstadd_back(&run, new);
	new->next = run;
	game->heroes->sprite.left = run;
	return (run);
}

t_list	*ft_load_north(t_game *game)
{
	t_list	*run;
	int		size;
	t_list	*new;

	size = SIZE;
	run = NULL;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/up/pl_up1.xpm", &size, &size)));
	game->heroes->sprite.st_up = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/up/pl_up2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/up/pl_up3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/up/pl_up4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/up/pl_up5.xpm", &size, &size));
	ft_lstadd_back(&run, new);
	new->next = run;
	game->heroes->sprite.up = run;
	return (run);
}

t_list	*ft_load_east(t_game *game)
{
	t_list	*run;
	int		size;
	t_list	*new;

	size = SIZE;
	run = NULL;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/right/pl_right1.xpm", &size, &size)));
	game->heroes->sprite.st_right = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/right/pl_right2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/right/pl_right3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/right/pl_right4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl/right/pl_right5.xpm", &size, &size));
	ft_lstadd_back(&run, new);
	new->next = run;
	game->heroes->sprite.right = run;
	return (run);
}

void	ft_load_hero(t_game *game)
{
	t_entity *hero;

	hero = game->heroes;
	hero->sprite.st = ft_lstnew(game->sprites.hero);
	hero->sprite.down = ft_load_south(game);
	hero->sprite.up = ft_load_north(game);
	hero->sprite.right = ft_load_east(game);
	hero->sprite.left = ft_load_west(game);
	game->sprites.hero_dying = load_death(game);
}
