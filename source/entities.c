#include "../includes/game.h"

t_entity	*ft_create_en(t_pos pos)
{
	t_entity	*entity;

	entity = (t_entity *) malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->pos = pos;
	entity->w_pos = ft_new_pos(pos.x * SIZE, pos.y * SIZE);
	entity->dir = 0;
	entity->move = 0;
	entity->next = NULL;
	return (entity);
}

void	ft_en_add_back(t_entity **lst, t_entity *new)
{
	t_entity	*elem;


	if (*lst)
	{
		elem = *lst;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		*lst = new;
}

//TODO ft_delete_en
//TODO free_enemies

void	ft_add_entities(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				ft_en_add_back(&game->heroes, ft_create_en(ft_new_pos(x, y)));
			if (game->map[y][x] == 'G')
				ft_en_add_back(&game->enemies, ft_create_en(ft_new_pos(x, y)));
			x++;
		}
		y++;
	}
}

void	ft_put_hero(t_game *game)
{
	t_entity	*hero;

	hero = game->heroes;
//	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.empty, hero->w_pos.x, hero->w_pos.y);
	if (hero->dir == W)
		ft_go_west(game, hero);
	if (hero->dir == E)
		ft_go_east(game, hero);
	if (hero->dir == S)
		ft_go_south(game, hero);
	if (hero->dir == N)
		ft_go_north(game, hero);
	if (hero->dir == ST)
		mlx_put_image_to_window(game->mlx_id, game->window, hero->sprite.st->content, hero->w_pos.x, hero->w_pos.y);
}

int	ft_is_there_en(t_game *game, int x, int y)
{
	t_entity	*en2;

	en2 = game->enemies;
	while (en2)
	{
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		if (en2->pos.x == x && en2->pos.y == y)
			return (0);
		en2 = en2->next;
	}
	return (1);
}

void	ft_update_legal_act(t_game *game, t_entity *en)
{
	en->legal.N = (!ft_strchr("1E", game->map[en->pos.y - 1][en->pos.x]));
	en->legal.S = (!ft_strchr("1E", game->map[en->pos.y + 1][en->pos.x]));
	en->legal.E = (!ft_strchr("1E", game->map[en->pos.y][en->pos.x + 1]));
	en->legal.W = (!ft_strchr("1E", game->map[en->pos.y][en->pos.x - 1]));
	if (game->heroes == en)
		return;
	en->legal.N *= ft_is_there_en(game, en->pos.x, en->pos.y - 1);
	en->legal.S *= ft_is_there_en(game, en->pos.x, en->pos.y + 1);
	en->legal.E *= ft_is_there_en(game, en->pos.x + 1, en->pos.y);
	en->legal.W *= ft_is_there_en(game, en->pos.x - 1, en->pos.y);
}

int	ft_is_mov_legal(t_entity *entity, int dir)
{
	if (dir == N && entity->legal.N)
		return (1);
	if (dir == W && entity->legal.W)
		return (1);
	if (dir == S && entity->legal.S)
		return (1);
	if (dir == E && entity->legal.E)
		return (1);
	if (dir == ST)
		return (1);
	return (0);
}

void	ft_open_doors(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.open_ex, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void    ft_door_checker(t_game *game, t_entity *entity, t_pos new)
{
	if (game->map[new.y][new.x] == 'E' && game->params->coins == 0)
	{
		printf("\nYou win!\nTotal number of moves: %d\nCollected coins: %d\n",
			   game->moves, game->all_coins);
		close_game(game);
	}
	if (game->map[new.y][new.x] == 'E')
	{
		entity->move = 0;
		entity->dir = ST;
		return;
	}
    entity->move = 1;
    entity->pos = new;
}

void	ft_move(t_entity *entity, t_game *game)
{
    t_pos pos;

	if (entity->dir == N && ft_is_mov_legal(entity, entity->dir))
		pos = ft_new_pos(entity->pos.x, entity->pos.y - 1);
	else if (entity->dir == W && ft_is_mov_legal(entity, entity->dir))
        pos = ft_new_pos(entity->pos.x - 1, entity->pos.y);
	else if (entity->dir == S && ft_is_mov_legal(entity, entity->dir))
        pos = ft_new_pos(entity->pos.x, entity->pos.y + 1);
	else if (entity->dir == E && ft_is_mov_legal(entity, entity->dir))
        pos = ft_new_pos(entity->pos.x + 1, entity->pos.y);
    else
        pos = ft_new_pos(0, 0);
	ft_memset(&game->map[entity->pos.y][entity->pos.x], \
		'0', game->map[entity->pos.y][entity->pos.x] == 'P');
	if (game->map[pos.y][pos.x] == 'C')
	{
		game->map[pos.y][pos.x] = '0';
		game->params->coins--;
	}
    if (pos.x && pos.y)
        ft_door_checker(game, entity, pos);
}

void	ft_next_dir(t_game *game)
{
	t_entity	*hero;

	hero = game->heroes;
	if (!hero->move)
	{
		ft_update_legal_act(game, hero);
		if (game->next_dir && ft_is_mov_legal(hero, game->next_dir)) {
			hero->prev_dir = hero->dir;
			hero->dir = game->next_dir;
		}
		else
			hero->dir = ST;
		ft_move(hero, game);
		hero->move = 1;
	}
}