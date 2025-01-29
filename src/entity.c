/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:18 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 16:44:36 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/entity.h"
#include "../inc/sprite.h"

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
