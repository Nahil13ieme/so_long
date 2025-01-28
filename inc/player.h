/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:12 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:27:33 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "sprite.h"
#include "vector2d.h"


typedef struct s_player
{
	t_vector2d	pos;
	t_vector2d	velocity;
	t_sprite	sprite;	
}	t_player;


#endif //PLAYER_H