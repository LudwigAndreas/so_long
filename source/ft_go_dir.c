#include "../includes/game.h"

void	ft_go_west(t_game *game, t_entity *entity)
{
	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x + 3, entity->w_pos.y);
	mlx_put_image_to_window(game->mlx_id, game->window, entity->sprite.left->content, entity->w_pos.x, entity->w_pos.y);
	entity->sprite.st = entity->sprite.st_left;
	if (game->frames % game->g_rate == 0)
		entity->sprite.left = entity->sprite.left->next;
}

void	ft_go_south(t_game *game, t_entity *entity)
{
	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x, entity->w_pos.y - 3);
	mlx_put_image_to_window(game->mlx_id, game->window, entity->sprite.down->content, entity->w_pos.x, entity->w_pos.y);
	entity->sprite.st = entity->sprite.st_down;
	if (game->frames % game->g_rate == 0)
		entity->sprite.down = entity->sprite.down->next;
}

void	ft_go_east(t_game *game, t_entity *entity)
{
	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x - 3, entity->w_pos.y);
	mlx_put_image_to_window(game->mlx_id, game->window, entity->sprite.right->content, entity->w_pos.x, entity->w_pos.y);
	entity->sprite.st = entity->sprite.st_right;
	if (game->frames % game->g_rate == 0)
		entity->sprite.right = entity->sprite.right->next;
}

void	ft_go_north(t_game *game, t_entity *entity)
{
	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, entity->w_pos.x, entity->w_pos.y + 3);
	mlx_put_image_to_window(game->mlx_id, game->window, entity->sprite.up->content, entity->w_pos.x, entity->w_pos.y);
	entity->sprite.st = entity->sprite.st_up;
	if (game->frames % game->g_rate == 0)
		entity->sprite.up = entity->sprite.up->next;
}