/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 16:43:47 by nbenhami         ###   ########.fr       */
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
int		init_level(t_game *game);
t_level	parse_level_info(int fd);

void	free_level(t_game *game)
{
	int	i;

	i = 0;
	if (game->level.layout)
	{
		while (i < game->level.width)
		{
			if (game->level.layout[i])
				free(game->level.layout[i]);
			i++;
		}
		free(game->level.layout);
	}
	free(game->level.entities);
}

int	init_level(t_game *game)
{
	int		fd;

	fd = open("level/level.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	game->level = parse_level_info(fd);
	if (game->level.height == 0 || game->level.width == 0)
		return (0);
	game->level.is_done = 0;
	game->level.has_exit = 0;
	game->level.has_player = 0;
	game->level.entities_count = 0;
	game->level.key_count = 0;
	game->level.entities = NULL;
	if (!check_level_info(&game->level)
		|| game->level.height < 4 || game->level.width < 4)
		return (0);
	game->level.entities = malloc(sizeof(t_entity)
			* game->level.entities_count);
	add_entities(game, &game->level);
	if (!init_player(game, &game->player))
		return (0);
	close(fd);
	return (1);
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
