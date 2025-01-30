/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:20 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 15:43:53 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/errors.h"
#include "../inc/game.h"

static void	free_game_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Game not loaded\n");
	(void)game;
	exit(EXIT_FAILURE);
}

static void	free_mlx_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Mlx not loaded\n");
	(void)game;
	exit(EXIT_FAILURE);
}

static void	free_window_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Window not loaded\n");
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

static void	free_main_buffer_img_ptr_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Main buffer img ptr not loaded\n");
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

static void	free_main_buffer_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Main buffer not loaded\n");
	mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

static void	free_sprite_manager_not_loaded(t_game *game, int child)
{
	if (!child)
		printf("Sprite manager not loaded\n");
	mlx_destroy_image(game->vars.mlx, game->main_buffer.img_ptr);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(EXIT_FAILURE);
}

static void	free_sprite_manager_not_fully_loaded(t_game *game, int child)
{
	if (!child)
		printf("Sprite manager not fully loaded\n");
	if (game->s_manager->wall)
		mlx_destroy_image(game->vars.mlx, game->s_manager->wall->img_ptr);
	if (game->s_manager->exit)
		mlx_destroy_image(game->vars.mlx, game->s_manager->exit->img_ptr);
	if (game->s_manager->key)
		mlx_destroy_image(game->vars.mlx, game->s_manager->key->img_ptr);
	if (game->s_manager->player)
		mlx_destroy_image(game->vars.mlx, game->s_manager->player->img_ptr);
	free(game->s_manager->wall);
	free(game->s_manager->exit);
	free(game->s_manager->key);
	free(game->s_manager->player);
	free(game->s_manager);
	free_sprite_manager_not_loaded(game, 1);
	exit(EXIT_FAILURE);
}

static void	free_fd_not_open(t_game *game, int child)
{
	if (!child)
		printf("Fd not open\n");
	free_sprite_manager_not_fully_loaded(game, 1);
	exit(EXIT_FAILURE);
}

static void	free_level(t_game *game, int child)
{
	int	i;

	i = 0;
	if (!child)
		printf("Level not loaded\n");
	if (game->level.layout)
	{
		while (i < game->level.width)
		{
			if (game->level.layout[i])
				free(game->level.layout[i]);
			i++;
		}
		free(game->level.layout);
	}
	free(game->level.entities);
	if (game->level.keys)
		free (game->level.keys);
	free_fd_not_open(game, 1);
}

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
