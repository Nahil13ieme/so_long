/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:36:16 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:47:51 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"
#include "../inc/game.h"
#include "../inc/sprite.h"
#include <stdio.h>

void	init_window(t_game *game)
{
	if (!game)
		return ;
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return ;
	game->vars.win = mlx_new_window(game->vars.mlx, WIN_W, WIN_H, "Game");
}

/*
	X Init layer
	Init entity
	Init UI
*/
int	init_texture(t_game *game)
{
	t_sprite	*tmp = &game->player.sprite;
	int			i;

	i = 0;
	tmp->img_ptr = mlx_xpm_file_to_image(game->vars.mlx, "img/idle.xpm", &tmp->width, &tmp->height);
	if (!tmp->img_ptr)
		return (0);
	tmp->buffer = mlx_get_data_addr (tmp->img_ptr, &tmp->bpp, &tmp->line_len, &tmp->endian);
	if (!tmp->buffer)
		return (0);
	game->main_buffer.img_ptr = mlx_new_image(game->vars.mlx, WIN_W, WIN_H);
	if (!game->main_buffer.img_ptr)
		return (0);
	game->main_buffer.buffer = mlx_get_data_addr
		(game->main_buffer.img_ptr, &game->main_buffer.bpp, &game->main_buffer.line_len, &game->main_buffer.endian);
	if (!game->main_buffer.buffer)
		return (0);
	game->main_buffer.width = WIN_W;
	game->main_buffer.height = WIN_H;
	
	return (1);
}

/*
	Background, entity, enemy, player, ui
*/

void	render(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.win);
	draw_sprite_to_buffer(&game->main_buffer, &game->player.sprite, 0, 0);
	draw_sprite_to_buffer(&game->main_buffer, &game->player.sprite, 0, 0);
	draw_sprite_to_buffer(&game->main_buffer, &game->player.sprite, 0, 0);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->main_buffer.img_ptr, 0, 0);
}