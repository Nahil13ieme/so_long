/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:54:08 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:52:54 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/level_check.h"
#include "../inc/level.h"
#include "../inc/entity.h"

int	check_level_info(t_level *level)
{
	int	i;
	int	j;

	i = 0;
	while (level->layout[i])
	{
		j = 0;
		while (level->layout[i][j])
		{
			if (!level->layout[i][j] && !check_borders(i, j, level->layout[i][j], level))
				return (0);
			if (!check_unique_entities(level->layout[i][j], level))
				return (0);
			if (level->layout != ' ')
				level->entities_count++;
			j++;
		}
		if (level->width != ft_strlen(level->layout[i]))
			return (0);
		i++;
	}

	return (1);
}

int	check_borders(int i, int j, char c, t_level *level)
{
	if (i == 0 || i == level->height - 1 || j == 0 || j == level->width - 1)
	{
		if (c != 'W')
			return (0);
	}
	return (1);
}

int	check_unique_entities(char c, t_level *level)
{
	if (c == 'P')
	{
		level->has_player += 1;
		if (level->has_player != 1)
			return (0);
	}
	if (c == 'E')
	{
		level->has_exit += 1;
		if (level->has_exit != 1)
			return (0);
	}
	return (1);
}

int	add_entities(t_level *level)
{
	level->entities = malloc(sizeof(t_entity) * (level->entities_count + 1));
	if (!level->entities)
		return (0);
	
}