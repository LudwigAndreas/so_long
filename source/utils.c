#include "../includes/game.h"

t_pos	ft_new_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

int	evclid(t_pos p1, t_pos p2)
{
	return (((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}
