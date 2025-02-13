/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/13 03:41:12 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/player.h"
#include "../inc/entity.h"
#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/level_check.h"
#include "../inc/level.h"	

/*
Regrouper les infos pour la carte
Puis charger les textures suivant les objets de la carte
*/

void	init_level(t_game *game);
t_level	parse_level_info(int fd);

int	check_dfs(t_level level)
{
	t_dfs	*dfs;

	dfs = malloc(sizeof(t_dfs));
	if (!dfs)
		return (0);
	dfs->key_count = 0;
	dfs->has_exit = 0;
	if (!init_dfs(dfs, level))
		return (free_dfs(dfs, level), 0);
	if (!dfs_layout(level, dfs))
		return (free_dfs(dfs, level), 0);
	return (free_dfs(dfs, level), 1);
}

void	init_level(t_game *game)
{
	int		fd;

	fd = open("level/level.ber", O_RDONLY);
	if (fd == -1)
		free_errors(game, FD_NOT_OPEN);
	game->level = parse_level_info(fd);
	if (game->level.height == 0 || game->level.width == 0)
		free_errors(game, LEVEL_NOT_LOADED);
	init_level_2(game);
	game->level.keys = malloc(sizeof(t_vector2d));
	if (!game->level.keys)
		free_errors(game, LEVEL_NOT_LOADED);
	if (!check_level_info(&game->level))
		free_errors(game, LEVEL_NOT_LOADED);
	game->level.entities = malloc(sizeof(t_entity)
			* game->level.entities_count);
	add_entities(game->s_manager, &game->level);
	if (!check_dfs(game->level))
		free_errors(game, LEVEL_NOT_LOADED);
	if (!init_player(game, &game->player))
		free_errors(game, LEVEL_NOT_LOADED);
	close(fd);
}

void	init_level_2(t_game *game)
{
	game->level.is_done = 0;
	game->level.has_exit = 0;
	game->level.has_player = 0;
	game->level.entities_count = 0;
	game->level.key_count = 0;
	game->level.entities = NULL;
}

t_level	parse_level_info(int fd)
{
	char	*line;
	t_level	level;

	level.width = 0;
	level.layout = NULL;
	line = get_next_line(fd);
	while ((line))
	{
		level.layout = ft_realloc(level.layout, sizeof(char *)
				* (level.width + 1));
		level.layout[level.width] = ft_strdup(line);
		free(line);
		level.width++;
		line = get_next_line(fd);
	}
	level.height = ft_strlen(level.layout[0]);
	return (level);
}
