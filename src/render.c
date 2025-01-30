/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:36:16 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:43 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"
#include "../inc/game.h"
#include "../inc/sprite.h"
#include <stdio.h>
#include <string.h>
#include "../inc/errors.h"

void	init_window(t_game *game)
{
	if (!game)
		free_errors(game, GAME_NOT_LOADED);
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		free_errors(game, MLX_NOT_LOADED);
	game->vars.win = mlx_new_window(game->vars.mlx, WIN_W, WIN_H, "Game");
	if (!game->vars.win)
		free_errors(game, WIN_NOT_LOADED);
}

/*
	X Init layer
	Init entity
	Init UI
*/
void	init_texture(t_game *game)
{
	game->main_buffer.img_ptr = mlx_new_image(game->vars.mlx, WIN_W, WIN_H);
	if (!game->main_buffer.img_ptr)
		free_errors(game, MAIN_BUFFER_IMG_PTR_NOT_LOADED);
	game->main_buffer.buffer = mlx_get_data_addr
		(game->main_buffer.img_ptr, &game->main_buffer.bpp,
			&game->main_buffer.line_len, &game->main_buffer.endian);
	if (!game->main_buffer.buffer)
		free_errors(game, MAIN_BUFFER_NOT_LOADED);
	game->main_buffer.width = WIN_W;
	game->main_buffer.height = WIN_H;
}

/*
	Background, entity, enemy, player, ui
*/

void	render(t_game *game)
{
	int	i;

	ft_memset(game->main_buffer.buffer, 0,
		WIN_W * WIN_H * (game->main_buffer.bpp / 8));
	mlx_clear_window(game->vars.mlx, game->vars.win);
	i = 0;
	while (i < game->level.entities_count)
	{
		if (game->level.entities[i].sprite && game->level.entities[i].is_active)
			draw_sprite_to_buffer(&game->main_buffer,
				game->level.entities[i].sprite, game->level.entities[i].pos.x,
				game->level.entities[i].pos.y);
		i++;
	}
	draw_sprite_to_buffer(&game->main_buffer, game->player.sprite,
		game->player.pos.x, game->player.pos.y);
	if (game->show_hitbox == 1)
		draw_sprite_to_buffer(&game->main_buffer, game->player.hit_box,
			game->player.pos.x, game->player.pos.y);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->main_buffer.img_ptr, 0, 0);
}
