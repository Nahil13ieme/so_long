/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 17:54:59 by nbenhami         ###   ########.fr       */
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

void	free_level(t_game *game);
void	init_level(t_game *game);
t_level	parse_level_info(int fd);

void	free_dfs(t_dfs *dfs, t_level level)
{
	int	i;

	i = -1;
	while (++i < level.width)
		if (dfs->visited[i])
			free(dfs->visited[i]);
	free(dfs->visited);
	free(dfs);
}

int	check_dfs(t_level level)
{
	t_dfs	*dfs;
	int		i;

	dfs = malloc(sizeof(t_dfs));
	if (!dfs)
		return (0);
	dfs->key_count = 0;
	dfs->has_exit = 0;
	dfs->pos = level.start;
	dfs->prev_pos = dfs->pos;
	dfs->visited = malloc(sizeof(int *) * level.width);
	if (!dfs->visited)
		return (free(dfs), 0);
	i = -1;
	while (++i < level.width)
	{
		dfs->visited[i] = malloc(sizeof(int) * level.height);
		if (!dfs->visited[i])
			return (free_dfs(dfs, level), 0);
		ft_memset(dfs->visited[i], 0, level.height * sizeof(int));
	}
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
	add_entities(game, &game->level);
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

void	add_entities(t_game *game, t_level *level)
{
	int			i;
	int			j;
	int			id;
	t_vector2d	pos;

	i = 0;
	id = 0;
	while (i < level->width)
	{
		j = 0;
		while (level->layout[i][j])
		{
			pos = (t_vector2d){i, j};
			if (level->layout[i][j] == 'W')
				level->entities[id] = new_entity(game->s_manager->wall, WALL, &id, pos);
			if (level->layout[i][j] == 'E')
				level->entities[id] = new_entity(game->s_manager->exit, EXIT, &id, pos);
			if (level->layout[i][j] == 'K')
				level->entities[id] = new_entity(game->s_manager->key, KEY, &id, pos);
			j++;
		}
		i++;
	}
}
