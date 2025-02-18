/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:09 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/13 03:32:12 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdlib.h>
# include <stdio.h>
# include "render.h"
# include "entity.h"
# include "sprite.h"
# include "utils.h"
# include "level.h"
# include "player.h"
# include "enemy.h"
# include "errors.h"
# include "level_check.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_vars	t_vars;

typedef struct s_game
{
	int					stop;
	int					show_hitbox;
	t_player			player;
	t_vars				vars;
	t_sprite			main_buffer;
	t_level				level;
	t_sprite_manager	*s_manager;
}	t_game;

void	init_game(t_game *game);

#endif //GAME_H