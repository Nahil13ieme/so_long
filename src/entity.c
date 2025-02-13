/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:18 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:39:35 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/entity.h"
#include "../inc/sprite.h"
#include "../inc/level.h"
#include "../inc/game.h"

t_entity	new_entity(t_sprite *sprite, t_type type, int *id, t_vector2d pos)
{
	t_entity	new;

	new.id = *id;
	new.type = type;
	new.pos = (t_vector2d){pos.y * 16, pos.x * 16};
	new.is_active = 1;
	new.sprite = sprite;
	new.box.min = new.pos;
	set_entity_name(&new);
	new.box.max = (t_vector2d){(pos.y + 1) * 16, (pos.x + 1) * 16};
	*id += 1;
	return (new);
}

void	set_entity_name(t_entity *entity)
{
	if (entity->type == WALL)
		entity->name = "WALL";
	if (entity->type == KEY)
		entity->name = "KEY";
	if (entity->type == EXIT)
		entity->name = "EXIT";
	if (entity->type == ENEMY)
		entity->name = "ENEMY";
}

void	add_entities(t_sprite_manager *s_man, t_level *level)
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
				level->entities[id] = new_entity(s_man->wall, WALL, &id, pos);
			if (level->layout[i][j] == 'E')
				level->entities[id] = new_entity(s_man->exit, EXIT, &id, pos);
			if (level->layout[i][j] == 'K')
				level->entities[id] = new_entity(s_man->key, KEY, &id, pos);
			j++;
		}
		i++;
	}
}
