#include "../includes/game.h"

t_list	*ft_load_south(t_game *game)
{
	t_list	*run;
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