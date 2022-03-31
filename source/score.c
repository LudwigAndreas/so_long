#include "../includes/game.h"

void	ft_put_font(t_game *g, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = g->sprites.font.zero;
	if (digit == 1)
		font = g->sprites.font.one;
	if (digit == 2)
		font = g->sprites.font.two;
	if (digit == 3)
		font = g->sprites.font.three;
	if (digit == 4)
		font = g->sprites.font.four;
	if (digit == 5)
		font = g->sprites.font.five;
	if (digit == 6)
		font = g->sprites.font.six;
	if (digit == 7)
		font = g->sprites.font.seven;
	if (digit == 8)
		font = g->sprites.font.eight;
	if (digit == 9)
		font = g->sprites.font.nine;
	mlx_put_image_to_window(g->mlx_id, g->window, font, \
	g->params->width * SIZE + SIZE * 3 - SIZE * i, LOGO_L);
}

void	ft_put_score(t_game *game)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = game->moves;
	while (i < 4)
	{
		digit = score % 10;
		score /= 10;
		ft_put_font(game, digit, i);
		i++;
	}
}


void    ft_update_score(t_game *game)
{
	mlx_put_image_to_window(game->mlx_id, game->window, game->sprites.score, game->width, 0);
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putendl_fd("", 1);
	ft_put_score(game);
}

void	next_direct(t_game *game, int dir)
{
	game->moves++;
	ft_update_score(game);
	game->next_dir = dir;
}
