#include "../includes/game.h"

char	**ft_duplicate_matrix(char **map)
{
	char	**out;
	char	*line;
	int		i;
	int		j;
	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
	}
	out = (char **) malloc(sizeof(char *) * (i + 1));
	int x = 0;
	int y = 0;
	while (map[x])
	{
		out[x] = (char *) malloc(sizeof(char) * (j + 1));
		while (map[x][y])
		{
			out[x][y] = map[x][y];
			y++;
		}
		x++;
	}
	for(int k = 0; k < i; k++)
	{
		ft_putendl_fd(out[k], 1);
	}
	return (out);
}