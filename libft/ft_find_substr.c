/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:58:38 by lsherry           #+#    #+#             */
/*   Updated: 2022/05/06 14:58:39 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_substr(const char *string, const char *sub)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	if (!string || !sub)
		return (-1);
	while (string[i + ft_strlen(sub) - 1])
	{
		j = 0;
		while (sub[j])
		{
			if (string[i + j] != sub[j])
				break ;
			j++;
			if (sub[j] == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}
