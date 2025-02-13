/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:44:41 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:31 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	free_game_not_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nGame not loaded\n");
	(void)game;
	exit(EXIT_FAILURE);
}

void	free_sprite_manager_not_fully_loaded(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nSprite manager not fully loaded\n");
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

void	free_fd_not_open(t_game *game, int child)
{
	if (!child)
		ft_printf("Error\nFd not open\n");
	free_sprite_manager_not_fully_loaded(game, 1);
	exit(EXIT_FAILURE);
}

void	free_level(t_game *game, int child)
{
	int	i;

	i = 0;
	if (!child)
		ft_printf("Level not loaded\n");
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
