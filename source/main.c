#include "../includes/map.h"
#include "../includes/game.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_params params;

	map = map_checker(argc, argv, &params);
	init_game(&params, map);
	return (0);
}
