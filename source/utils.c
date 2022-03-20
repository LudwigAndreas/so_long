#include "../includes/game.h"

char	**ft_duplicate_matrix(char **map)
{
	char	**out;
	int		i;
	int		x;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	out = (char **) malloc(sizeof(char *) * (i + 1));
	x = 0;
	while (map[x])
	{
		out[x] = ft_strdup(map[x]);
		x++;
	}
	out[x] = NULL;
	return (out);
}

t_pos	ft_new_pos(int x, int y)
{
	t_pos pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}