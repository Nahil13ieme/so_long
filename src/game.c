/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:21 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:12 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/render.h"

void free_game(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_image(game->vars.mlx, game->player.sprite.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(1);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	return (0);
}

int	game_loop(t_game *game)
{
	render(game);
	return (1);
}

void	init_game(t_game *game)
{
	init_window(game);
	if (!init_level(game))
		free_game(game);
	if (!init_texture(game))
		free_game(game);
	mlx_hook(game->vars.win, 2, 1L << 0, handle_input, game);
	mlx_loop_hook(game->vars.mlx, game_loop, game);
}
