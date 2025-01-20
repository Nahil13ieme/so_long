/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:04 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 15:13:22 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "texture.h"
#include "game_logic.h"

typedef struct s_box	t_box;

typedef struct s_player
{
	int					hp;
	int					is_dead;
	int					step;
	int					can_finish;
	struct s_pos		pos;
	struct s_texture	texture;
	struct s_box			hitbox;
}	t_player;

void	init_player(t_player *player, t_pos pos, t_texture texture);
void	move_player(t_player *player, t_game_context *game_context, int x, int y);

#endif