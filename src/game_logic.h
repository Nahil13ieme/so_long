/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:47:06 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 15:13:01 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOGIC_H
# define GAME_LOGIC_H

#include "texture.h"
#include <stdlib.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "keycode.h"
#include "player.h"
#include "collider.h"

typedef struct s_texture	t_texture;
typedef struct s_box		t_box;

typedef enum e_object_type
{
	PLAYER,
	ENEMY,
	ITEM,
	WALL,
	SECRET_WALL,
	DOOR,
	EXIT,
}	t_object_type;

typedef struct s_pos
{
	int	x;
	int	y;
	int	z;
}	t_pos;

typedef struct s_game_object
{
	char				*type;
	struct s_pos		pos;
	struct s_texture	texture;
	struct s_box			hitbox;
	t_object_type		object_type;
}	t_game_object;


typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_game_context
{
	int						game_state;
	struct s_player			player;
	struct s_game_object	*game_objects;
	int						object_count;
	struct s_vars			vars;
}	t_game_context;

void	init_game(void *mlx, t_game_context *game_context);
int		handle_input(int keycode, t_game_context *game_context);
int		game_loop(t_game_context *game_context);

#endif