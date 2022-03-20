#include "../includes/map.h"

t_params	ft_null_params(void)
{
	t_params	params;

//	params = (t_params *) malloc(sizeof(t_params));
//	if (!params)
//		return (NULL);
	params.coins = 0;
	params.foes = 0;
	params.exits = 0;
	params.length = 0;
	params.players = 0;
	params.width = 0;
	return (params);
}

void	map_error(char *str, char *to_free1, char *to_free_2, t_params *params)
{
	ft_putendl_fd(str, 2);
	if (to_free1 != NULL)
		free(to_free1);
	if (to_free_2 != NULL)
		free(to_free_2);
	if (params != NULL)
		free(params);
	exit(0);
}

char	**map_checker(int argc, char **argv, t_params *params)
{
	int		fd;

	if (argc < 2)
		map_error("Invalid number of arguments", NULL, NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		map_error("File not found", NULL, NULL, NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		map_error("Invalid file extension", NULL, NULL, NULL);
	return (map_parser(fd, params));
}

char	*map_to_line(int fd, t_params *params)
{
	char	*line;
	char	*out;

	out = malloc(sizeof(char ));
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !out)
			break ;
		if (line[0] == '\n')
			continue ;
		line_validator(line, params, out);
		if (params->length == 1)
			check_rect(line, out, params);
		out = ft_gnl_strjoin(out, line);
		free(line);
	}
	param_validator(params, out);
	return (out);
}

char	**map_parser(int fd, t_params *params)
{
	char	**map;
	char	*map_line;

	*params = ft_null_params();
	map_line = map_to_line(fd, params);
	map = ft_split(map_line, '\n');
	free(map_line);
	return (map);
}