/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 00:10:52 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "../gnl_bonus/get_next_line.h"

/*
Regrouper les infos pour la carte, puis charger les textures suivant les objets de la carte
*/

void	free_level(t_game *game)
{
	int	i;

	i = 0;
	while (game->level.layout)
	{
		if (game->level.layout[i])
			free(game->level.layout[i]);
		i++;
	}
	free(game->level.layout);
}

int	init_level(t_game *game)
{
	int		fd;

	fd = open("level/level.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	game->level = parse_level_info(fd);
	if (!check_level_info(game->level))
	{
		free_level(game);
		return (0);
	}
	close(fd);
	return (1);
}

t_level	parse_level_info(int fd)
{
	char	*line;
	t_level	level;
	
	line = get_next_line(fd);
	level.height = 1;
	level.layout = ft_realloc(level.layout, sizeof(char *) * (level.height + 1));
	level.layout[level.height] = ft_strdup(line);
	while (line)
	{
		level.layout = ft_realloc(level.layout, sizeof(char *) * (level.height + 1));
		level.layout[level.height] = ft_strdup(line);
		free(line);
		level.height++;
	}
	return (level);
}

int	check_level_info(t_level level)
{
	int	i;
	int	j;

	i = 0;
	while (level.layout[i]
	{
		while (layout[i][j])
		{
			if (!check_borders(i, j, layout[i][j]))
			j++;
		}
		i++;
	})
	return (1);
}