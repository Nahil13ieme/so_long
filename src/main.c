/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:53:06 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/26 18:38:53 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "stdlib.h"
#include "../inc/game.h"
#include "../inc/render.h"

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	
	init_game(&game);
	mlx_loop(game.vars.mlx);
	return (0);
}
