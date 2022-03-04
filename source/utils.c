#include "../includes/game.h"

char	**ft_duplicate_matrix(char **map)
{
	char	**out;
	int		i;
	int		j;
	int		x;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
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