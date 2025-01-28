/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:25 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 17:59:56 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/player.h"
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
	if (game->level.layout)
	{
		while (i < game->level.height)
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
	game->level.entities = NULL;
	if (!check_level_info(&game->level) ||
		game->level.height < 4 || game->level.width < 4)
		return (0);
	game->level.entities = malloc(sizeof(t_entity) * game->level.entities_count);
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


	level.height = 0;
	level.layout = NULL;
	while ((line = get_next_line(fd)))
	{
		level.layout = ft_realloc(level.layout, sizeof(char *) * (level.height + 1));
		level.layout[level.height] = ft_strdup(line);
		free(line);
		level.height++;
	}
	level.width = ft_strlen(level.layout[0]);
	return (level);
}

void	add_entities(t_game *game, t_level *level)
{
	int	i;
	int	j;
	int id;

	i = 0;
	id = 0;
	while (i < level->height)
	{
		j = 0;
		while (level->layout[i][j])
		{
			if (level->layout[i][j] == 'W')
			{
				add_entities2(&level->entities[id], game->s_manager->wall, id, i, j);
				id++;
			}
			if (level->layout[i][j] == 'E')
			{
				add_entities2(&level->entities[id], game->s_manager->exit, id, i, j);
				level->entities->id = id;
				id++;
			}
			j++;
		}
		i++;
	}
}

void	add_entities2(t_entity *entity, t_sprite *sprite, int id, int i, int j)
{
	entity->id = id;
	entity->pos = (t_vector2d){i * 16, j * 16};
	entity->box.min = entity->pos;
	entity->box.max = (t_vector2d){(i + 1) * 16, (j + 1) * 16};
	entity->sprite = sprite;
}
