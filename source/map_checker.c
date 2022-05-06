/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:12:45 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:12:46 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

t_params	ft_null_params(void)
{
	t_params	params;

	params.coins = 0;
	params.exits = 0;
	params.length = 0;
	params.players = 0;
	params.width = 0;
	return (params);
}

void	m_error(char *str, char *to_free1, char *to_free_2)
{
	ft_putendl_fd(str, 2);
	if (to_free1)
		free(to_free1);
	if (to_free_2)
		free(to_free_2);
	exit(0);
}

char	**map_checker(int argc, char **argv, t_params *params)
{
	int		fd;

	if (argc != 2)
		m_error("Invalid number of arguments", NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		m_error("File not found", NULL, NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		m_error("Invalid file extension", NULL, NULL);
	return (map_parser(fd, params));
}

char	*map_to_line(int fd, t_params *params)
{
	char	*line;
	char	*out;

	out = (char *) malloc(sizeof(char ));
	out[0] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		line_validator(line, params, out);
		if (params->length == 1)
			check_walls(line, out, params);
		out = ft_strjoin_gnl(out, line);
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
	close(fd);
	return (map);
}
