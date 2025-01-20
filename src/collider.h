/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:19:24 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 14:59:24 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLIDER_H
# define COLLIDER_H

# include "game_logic.h"

typedef struct s_game_object	t_game_object;
typedef struct s_player			t_player;
typedef struct s_game_context	t_game_context;
typedef struct s_pos			t_pos;

typedef struct s_box
{
	t_pos	min;
	t_pos	max;
}	t_box;

int		is_colliding(t_game_object *object1, t_game_object *object2);
int		is_colliding_with_player(t_game_object *object, t_player *player);
int		is_colliding_with_wall(t_game_object *object, t_game_context *game_context);

#endif // COLLIDER_H