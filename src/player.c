/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:11 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 17:16:48 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/player.h"
#include "../inc/collision.h"
#include <math.h>

int	init_player(t_game *game, t_player *player)
{
	player->pos.x = 75;
	player->pos.y = 75;
	player->last_pos = player->pos;
	player->step = 0;
	player->sprite = game->s_manager->player;
	if (!player->sprite || !player->sprite->buffer)
	{
		printf("failed init player");
		return (0);
	}
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
	new_hitbox = (t_box){(t_vector2d){pos.x + 4, pos.y + 4},
		(t_vector2d){pos.x + 12, pos.y + 16}};
	i = 0;
	while (i < game->level.entities_count)
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
		i++;
	}
	if (abs(game->player.pos.x - game->player.last_pos.x) >= 16 || abs(game->player.pos.y - game->player.last_pos.y) >= 16)
	{
		game->player.last_pos = pos;
		game->player.step++;
		printf("Step %d\n",game->player.step);
	}
	game->player.pos = pos;
}

void	remove_key(t_game *game, int id)
{
	game->level.entities[id].is_active = 0;
	game->player.key += 1;
}
