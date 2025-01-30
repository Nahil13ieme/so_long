/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:54:08 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 22:05:02 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/level_check.h"
#include "../inc/level.h"
#include "../inc/entity.h"
#include "../inc/game.h"

int	check_level_info(t_level *level)
{
	int	i;
	int	j;

	i = 0;
	while (i < level->width)
	{
		j = 0;
		while (level->layout[i][j])
		{
			if (!level->layout[i][j] && !check_borders(i,
				j, level->layout[i][j], level))
				return (0);
			if (!check_unique_entities(level->layout[i][j], level, i, j))
				return (0);
			if (level->layout[i][j] != ' ' && level->layout[i][j] != 'P')
				level->entities_count++;
			j++;
		}
		if (level->height != ft_strlen(level->layout[i]))
			return (0);
		i++;
	}
	if (level->height < 4 || level->width < 4)
		return (0);
	return (1);
}

int	check_borders(int i, int j, char c, t_level *level)
{
	if (i == 0 || i == level->width - 1 || j == 0 || j == level->height - 1)
	{
		if (c != 'W')
			return (0);
	}
	return (1);
}

int	check_unique_entities(char c, t_level *level, int i, int j)
{
	if (c == 'P')
	{
		level->has_player += 1;
		if (level->has_player != 1)
			return (0);
		level->start = (t_vector2d){i, j};
	}
	if (c == 'E')
	{
		level->has_exit += 1;
		if (level->has_exit != 1)
			return (0);
		level->end = (t_vector2d){i, j};
	}
	if (c == 'K')
	{
		level->key_count += 1;
		level->keys = ft_realloc(level->keys, sizeof(t_vector2d) * level->key_count);
		level->keys[level->key_count - 1] = (t_vector2d){i,j};
	}
	return (1);
}

void	check_key_looted(t_game *game)
{
	if (game->level.key_count != game->player.key)
		return ;
	game->level.is_done = 1;
}
