/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:12 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 17:02:55 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "sprite.h"
#include "vector2d.h"

typedef struct s_game	t_game;

typedef struct s_player
{
	t_vector2d	pos;
	t_vector2d	velocity;
	t_sprite	*sprite;	
}	t_player;

int		init_player(t_game *game, t_player *player);
void	move_player(t_game *game);

#endif //PLAYER_H