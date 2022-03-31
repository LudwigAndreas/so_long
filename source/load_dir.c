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
		"resources/sprites/pl2/down/pl1.xpm", &size, &size)));
	game->heroes->sprite.st_down = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/down/pl2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/down/pl3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/down/pl4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/down/pl5.xpm", &size, &size));
	ft_lstadd_back(&run, new);
	new->next = run;
	game->heroes->sprite.down = run;
	return (run);
}

//t_list	*ft_load_south(t_game *game)
//{
//	t_list	*run;
//	int		size;
//	t_list	*new;
//
//	size = SIZE;
//	run = NULL;
//	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
//		"resources/sprites/pl2/down/pl1.xpm", &size, &size)));
//	game->heroes->sprite.st_down = run;
//	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
//		"resources/sprites/pl2/down/pl2.xpm", &size, &size)));
//	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
//		"resources/sprites/pl2/down/pl3.xpm", &size, &size)));
//	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
//		"resources/sprites/pl2/down/pl4.xpm", &size, &size)));
//	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
//		"resources/sprites/pl2/down/pl5.xpm", &size, &size));
//	ft_lstadd_back(&run, new);
//	new->next = run;
//	game->heroes->sprite.down = run;
//	return (run);
//}

t_list	*ft_load_west(t_game *game)
{
	t_list	*run;
	int		size;
	t_list	*new;

	size = SIZE;
	run = NULL;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/left/pl1.xpm", &size, &size)));
	game->heroes->sprite.st_left = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/left/pl2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/left/pl3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/left/pl4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/left/pl5.xpm", &size, &size));
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
		"resources/sprites/pl2/up/pl1.xpm", &size, &size)));
	game->heroes->sprite.st_up = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/up/pl2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/up/pl3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/up/pl4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/up/pl5.xpm", &size, &size));
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
		"resources/sprites/pl2/right/pl1.xpm", &size, &size)));
	game->heroes->sprite.st_right = run;
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/right/pl2.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/right/pl3.xpm", &size, &size)));
	ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/right/pl4.xpm", &size, &size)));
	new = ft_lstnew(mlx_xpm_file_to_image(game->mlx_id, \
		"resources/sprites/pl2/right/pl5.xpm", &size, &size));
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
}
