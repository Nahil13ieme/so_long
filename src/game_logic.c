#include "game_logic.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:46:54 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/17 06:46:58 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_logic.h"

void init_game(void *mlx, t_game_context *game_context)
{
	game_context->game_state = 0;
	game_context->player.pos.x = 0;
	game_context->player.pos.y = 0;
	game_context->player.pos.z = 1;
	game_context->player.is_dead = 0;
	game_context->player.texture.file_path = "img/idle.xpm";

	game_context->object_count = 0;
	game_context->game_objects = NULL;
	load_texture(mlx, &game_context->player.texture, game_context->player.texture.file_path);
}

void update()
{

}