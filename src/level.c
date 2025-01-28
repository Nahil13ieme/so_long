/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:18 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/level_check.h"

/*
Regrouper les infos pour la carte, puis charger les textures suivant les objets de la carte
*/

void	free_level(t_game *game);
int		init_level(t_game *game);
t_level	parse_level_info(int fd);

void	free_level(t_game *game)
{
	int	i;

	i = 0;
	while (game->level.layout[i])
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
	game->level.is_done = 0;
	game->level.has_exit = 0;
	game->level.has_player = 0;
	game->level.entities_count = 0;
	game->level.entities = NULL;
	if (!check_level_info(&game->level))
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
	level.width = ft_strlen(line);
	level.height = 0;
	level.layout = NULL;
	while (line)
	{
		level.layout = realloc(level.layout, sizeof(char *) * (level.height + 1));
		level.layout[level.height] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		level.height++;
	}
	return (level);
}