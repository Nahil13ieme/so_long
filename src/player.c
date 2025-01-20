#include "player.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:02 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/19 13:34:03 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void init_player(t_player *player, t_pos pos, t_texture texture)
{
	player->hp = 100;
	player->is_dead = 0;
	player->step = 0;
	player->pos = pos;
	player->texture = texture;
}

void	move_player(t_player *player, t_game_context *game_context, int x, int y)
{
	t_pos	new_pos;
	int		i;
	
	new_pos.x = player->pos.x + x;
	new_pos.y = player->pos.y + y;
	i = 0;
	while(i < game_context->object_count)
	{
		if (is_collision(new_pos, game_context->game_objects[i].hitbox))
		{
			if (game_context->game_objects[i].object_type == WALL)
				return ;
			if (game_context->game_objects[i].object_type == EXIT && player->can_finish)
			{
				mlx_destroy_window(game_context->vars.mlx, game_context->vars.win);
				exit(0);
			}
			if (game_context->game_objects[i].object_type == ITEM)
			{
				player->can_finish = 1;
				game_context->game_objects[i].object_type = WALL;
			}
		}
		i++;
	}
	player->pos = new_pos;
	player->step++;
}