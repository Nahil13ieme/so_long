/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:21 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 17:48:17 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../inc/render.h"
#include "../inc/time_game.h"

void free_game(t_game *game)
{
	free_level(game);
	if (game->s_manager)
		free_sprite_manger(game);
	if (game->main_buffer.img_ptr && game->main_buffer.buffer)
		mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	 if (keycode == 'w')
		game->player.velocity.y = -1;
	if (keycode == 'a')
		game->player.velocity.x = -1;
	if (keycode == 's')
		game->player.velocity.y = 1;
	if (keycode == 'd')
		game->player.velocity.x = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == 's')
		game->player.velocity.y = 0;
	if (keycode == 'a' || keycode == 'd')
		game->player.velocity.x = 0;
	return (0);
}

int	game_loop(t_game *game)
{
	render(game);
	move_player(game);
	cap_fps();
	return (1);
}

void	init_game(t_game *game)
{
	init_window(game);
	game->s_manager = init_sprite_manager(game);
	if (!game->s_manager)
		free_game(game);
	if (!init_level(game))
		free_game(game);
	if (!init_texture(game))
		free_game(game);
	mlx_hook(game->vars.win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->vars.win, 3, 1L << 1, handle_key_release, game);
	mlx_loop_hook(game->vars.mlx, game_loop, game);
}
