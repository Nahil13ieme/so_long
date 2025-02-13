/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:41:27 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/13 03:32:28 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	free_mlx_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nMlx not loaded\n");
	(void)game;
	exit(EXIT_FAILURE);
}

void	free_window_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nWindow not loaded\n");
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

void	free_main_buffer_img_ptr_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nMain buffer img ptr not loaded\n");
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

void	free_main_buffer_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nMain buffer not loaded\n");
	mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

void	free_sprite_manager_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nError\nSprite manager not loaded\n");
	mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}
