/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:31:37 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:31:39 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*Структура содержащая стандартные параметры карты*/
typedef struct s_params
{
	int	width;
	int	length;
	int	exits;
	int	players;
	int	coins;
}				t_params;

char	**map_checker(int argc, char **argv, t_params *params);
char	**map_parser(int fd, t_params *params);
void	line_validator(char *l, t_params *params, char *out);
void	param_validator(t_params *params, char *out);
void	check_walls(char *line, char *out, t_params *params);
void	m_error(char *str, char *to_free1, char *to_free_2);
#endif
