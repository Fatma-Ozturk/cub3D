/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:11:28 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:11:31 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_str_space(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] <= 32)
			count++;
		i++;
	}
	if ((int)ft_strlen(s) == count)
		return (1);
	return (-1);
}

/* void put_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        printf("%d %s",i, map[i]);
        i++;
    }
    printf("\n");
}
 */