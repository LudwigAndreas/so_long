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

t_list	*ft_load_south(t_game *game, char *path, int mode)
{
	t_list	*run;
	int		size;
	char 	*name;
	int		i;
	char	*s;

	size = SIZE;
	run = NULL;
	i = 1;
	name = ft_substr("down/1.xpm", 0, 10);
	while (i != 6)
	{
		s = ft_strjoin(path, name);
		ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id,\
		s, &size, &size)));
		ft_putendl_fd(s, 1);
		ft_memset(&name[5], '1' + i, 1);
		free(s);
		i++;
	}
	free(name);
	if (mode)
	{
		game->heroes->sprite.st_down = run;
		game->heroes->sprite.down = run;
		run->next->next->next->next->next = run;
	}
	return (run);
}

t_list	*ft_load_west(t_game *game, char *path, int mode)
{
	t_list	*run;
	int		size;
	char 	*name;
	int		i;
	char	*s;

	size = SIZE;
	run = NULL;
	i = 1;
	name = ft_substr("left/1.xpm", 0, 10);
	while (i != 6)
	{
		s = ft_strjoin(path, name);
		ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id,\
		s, &size, &size)));
		ft_putendl_fd(s, 1);
		ft_memset(&name[5], '1' + i, 1);
		free(s);
		i++;
	}
	free(name);
	if (mode)
	{
		game->heroes->sprite.st_left = run;
		game->heroes->sprite.left = run;
		run->next->next->next->next->next = run;
	}
	return (run);
}

t_list	*ft_load_north(t_game *game, char *path, int mode)
{
	t_list	*run;
	int		size;
	char 	*name;
	int		i;
	char	*s;

	size = SIZE;
	run = NULL;
	i = 1;
	name = ft_substr("up/1.xpm", 0, 8);
	while (i != 6)
	{
		s = ft_strjoin(path, name);
		ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id,\
		s, &size, &size)));
		ft_putendl_fd(s, 1);
		ft_memset(&name[3], '1' + i, 1);
		free(s);
		i++;
	}
	free(name);
	if (mode)
	{
		game->heroes->sprite.st_up = run;
		game->heroes->sprite.up = run;
		run->next->next->next->next->next = run;
	}
	return (run);
}

t_list	*ft_load_east(t_game *game, char *path, int mode)
{
	t_list	*run;
	int		size;
	char 	*name;
	int		i;
	char	*s;

	size = SIZE;
	run = NULL;
	i = 1;
	name = ft_substr("right/1.xpm", 0, 11);
	while (i != 6)
	{
		s = ft_strjoin(path, name);
		ft_lstadd_back(&run, ft_lstnew(mlx_xpm_file_to_image(game->mlx_id,\
		s, &size, &size)));
		ft_putendl_fd(s, 1);
		ft_memset(&name[6], '1' + i, 1);
		free(s);
		i++;
	}
	free(name);
	if (mode)
	{
		game->heroes->sprite.st_right = run;
		game->heroes->sprite.right = run;
		run->next->next->next->next->next = run;
	}
	return (run);
}

void	ft_load_hero(t_game *game)
{
	t_entity *hero;

	hero = game->heroes;
	hero->sprite.st = ft_lstnew(game->sprites.hero);
	hero->sprite.down = ft_load_south(game, "resources/sprites/pl/", 1);
	hero->sprite.up = ft_load_north(game, "resources/sprites/pl/", 1);
	hero->sprite.right = ft_load_east(game, "resources/sprites/pl/", 1);
	hero->sprite.left = ft_load_west(game, "resources/sprites/pl/", 1);
}