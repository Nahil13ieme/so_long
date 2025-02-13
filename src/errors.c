/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:20 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:45:36 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/errors.h"
#include "../inc/game.h"
#include "../ft_printf/ft_printf.h"

void	free_errors(t_game *game, int i)
{
	if (i == GAME_NOT_LOADED)
		free_game_not_loaded(game, 0);
	else if (i == MLX_NOT_LOADED)
		free_mlx_not_loaded(game, 0);
	else if (i == WIN_NOT_LOADED)
		free_window_not_loaded(game, 0);
	else if (i == MAIN_BUFFER_IMG_PTR_NOT_LOADED)
		free_main_buffer_img_ptr_not_loaded(game, 0);
	else if (i == MAIN_BUFFER_NOT_LOADED)
		free_main_buffer_not_loaded(game, 0);
	else if (i == SPRITE_MANAGER_NOT_LOADED)
		free_sprite_manager_not_loaded(game, 0);
	else if (i == SPRITE_MANAGER_NOT_FULLY_LOADED)
		free_sprite_manager_not_fully_loaded(game, 0);
	else if (i == FD_NOT_OPEN)
		free_fd_not_open(game, 0);
	else if (i == LEVEL_NOT_LOADED)
		free_level(game, 0);
}

void	free_all(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->player.hit_box->img_ptr);
	free(game->player.hit_box);
	free_level(game, 1);
}
