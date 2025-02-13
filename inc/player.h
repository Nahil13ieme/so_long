/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:12 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:56:45 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "sprite.h"
# include "vector2d.h"

typedef struct s_game	t_game;

typedef struct s_player
{
	int			key;
	int			step;
	t_vector2d	pos;
	t_vector2d	last_pos;
	t_vector2d	velocity;
	t_sprite	*sprite;
	t_sprite	*hit_box;
	t_box		hitbox;
}	t_player;

int		init_player(t_game *game, t_player *player);
void	move_player(t_game *game);
void	remove_key(t_game *game, int id);;
void	update_step(t_player *player, t_vector2d pos);

#endif //PLAYER_H