/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:11 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 14:23:28 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/player.h"
#include "../inc/collision.h"
#include "../inc/utils.h"
#include <math.h>

int	init_player(t_game *game, t_player *player)
{
	player->pos.x = game->level.start.x * 16;
	player->pos.y = game->level.start.y * 16;
	player->last_pos = player->pos;
	player->step = 0;
	player->sprite = game->s_manager->player;
	player->hitbox.min = (t_vector2d){player->pos.x - 1, player->pos.y};
	player->hitbox.max = (t_vector2d){player->pos.x + 12, player->pos.y + 16};
	if (!player->sprite || !player->sprite->buffer)
	{
		printf("failed init player");
		return (0);
	}
	player->hit_box = draw_box(game->vars.mlx, player->hitbox.min, player->hitbox.max);
	player->velocity.x = 0;
	player->velocity.y = 0;
	player->key = 0;
	return (1);
}

void	move_player(t_game *game)
{
	t_vector2d	pos;
	t_box		new_hitbox;
	int			i;

	pos.x = game->player.pos.x + game->player.velocity.x;
	pos.y = game->player.pos.y + game->player.velocity.y;
	new_hitbox = (t_box){(t_vector2d){pos.x + 1, pos.y + 2},
		(t_vector2d){pos.x + 12, pos.y + 15}};
	i = -1;
	while (++i < game->level.entities_count)
	{
		if (is_colliding(new_hitbox, game->level.entities[i].box)
			&& game->level.entities[i].is_active)
		{
			if (game->level.entities[i].type == WALL)
				return ;
			if (game->level.entities[i].type == KEY)
				remove_key(game, i);
			if (game->level.entities[i].type == EXIT)
				if (game->level.is_done)
					game->stop = 1;
		}
	}
	update_step(&game->player, pos);
	game->player.pos = pos;
}

void	update_step(t_player *player, t_vector2d pos)
{
	if (abs(player->pos.x - player->last_pos.x) >= 16 || abs(player->pos.y -player->last_pos.y) >= 16)
	{
		player->last_pos = pos;
		player->step++;
		printf("Step %d\n", player->step);
	}
}

void	remove_key(t_game *game, int id)
{
	game->level.entities[id].is_active = 0;
	game->player.key += 1;
}
