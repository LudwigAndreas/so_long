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

void	line_validator(char *l, t_params *params, char *out)
{
	int	i;

	i = -1;
	while (l[++i])
	{
		if (l[i] == 'C')
			params->coins++;
		if (l[i] == 'E')
			params->exits++;
		if (l[i] == 'P')
			params->players++;
		if (!ft_strchr("01CEPG\n", l[i]))
			break ;
	}
	params->length++;
	if (l[0] != '1' && l[ft_strlen(l) - 1] != '1')
		m_error("Map must be surrounded by walls", l, out);
	if (params->width != 0 && params->width != (int ) ft_strlen(l) - 1)
		m_error("Map must be rectangular or there is no \\n in the end of file",
			l, out);
	params->width = (int ) ft_strlen(l) - 1;
	if (i != (int ) ft_strlen(l))
		m_error("Invalid symbol(s) in map", l, out);
}

void	check_walls(char *line, char *out, t_params *params)
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
				m_error("Map must be surrounded by walls!", line, out);
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
				m_error("Map must be surrounded by walls!", line, out);
			len--;
		}
	}
}

void	param_validator(t_params *params, char *out)
{
	if (params->width == 0 || params->length == 0)
		m_error("Map is empty", out, NULL);
	else if (!params->exits)
		m_error("Invalid number of exits", out, NULL);
	else if (params->players != 1)
		m_error("Invalid number of players", out, NULL);
	else if (!params->coins)
		m_error("Invalid number of coins", out, NULL);
	check_walls(NULL, out, params);
}
