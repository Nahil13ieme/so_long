/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:04 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:49:17 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "vector2d.h"
# include "sprite.h"
# include "collision.h"

typedef struct s_vector2d	t_vector2d;
typedef struct s_game		t_game;
typedef struct s_level		t_level;

typedef enum e_type
{
	WALL,
	KEY,
	EXIT,
	ENEMY	
}	t_type;

typedef struct s_entity
{
	int			id;
	char		*name;
	int			is_active;
	t_type		type;
	t_sprite	*sprite;
	t_vector2d	pos;
	t_vector2d	velocity;
	t_box		box;
}	t_entity;

t_entity	new_entity(t_sprite *sprite, t_type type, int *id, t_vector2d pos);
void		set_entity_name(t_entity *entity);
void		add_entities(t_sprite_manager *s_man, t_level *level);

#endif //ENTITY_H