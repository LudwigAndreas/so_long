/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:12:56 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:12:57 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

void	line_validator(char *line, t_params *params, char *out)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			params->coins++;
		if (line[i] == 'E')
			params->exits++;
		if (line[i] == 'P')
			params->players++;
		if (line[i] == 'F')
			params->foes++;
		if (!ft_strchr("01CEPG\n", line[i]))
			break ;
		i++;
	}
	params->length++;
	if (line[0] != '1' && line[ft_strlen(line) - 1] != '1')
		map_error("Map must be surrounded by walls", line, out);
	if (params->width != 0 && params->width != (int ) ft_strlen(line) - 1)
		map_error("Map must be rectangular", line, out);
	params->width = (int ) ft_strlen(line) - 1;
	if (i != (int ) ft_strlen(line))
		map_error("Invalid symbol(s) in map", line, out);
}

void	check_rect(char *line, char *out, t_params *params)
{
	int	i;
	int	len;

	if (line != NULL)
	{
		len = (int ) ft_strlen(line);
		i = 0;
		while (i < len - 1)
		{
			if (line[i++] != '1')
				map_error("Map must be surrounded by walls!", line, out);
		}
	}
	else
	{
		i = (int ) ft_strlen(out);
		len = params->width;
		i -= 2;
		while (len > 0)
		{
			if (out[i - len + 1] != '1')
				map_error("Map must be surrounded by walls!", line, out);
			len--;
		}
	}
}

void	param_validator(t_params *params, char *out)
{
	if (params->width == 0 || params->length == 0)
		map_error("Map is empty", out, NULL);
	else if (!params->exits)
		map_error("Invalid number of exits", out, NULL);
	else if (params->players != 1)
		map_error("Invalid number of players", out, NULL);
	else if (!params->coins)
		map_error("Invalid number of coins", out, NULL);
	check_rect(NULL, out, params);
}
