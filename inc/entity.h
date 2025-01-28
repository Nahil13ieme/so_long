/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:04 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 17:25:12 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

#include "vector2d.h"
#include "sprite.h"
#include "collision.h"

typedef struct s_vector2d	t_vector2d;
typedef struct s_game	t_game;

typedef struct s_entity
{
	int			id;
	char		*name;
	int			is_active;
	t_sprite	*sprite;
	t_vector2d	pos;
	t_vector2d	velocity;
	t_box		box;
}	t_entity;

void		init_entity(t_game *game, char *name, t_entity *entity);

#endif //ENTITY_H