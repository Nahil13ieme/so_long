/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:39:32 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/17 07:02:59 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"

int handle_keypress(int keycode, t_vars *vars) 
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	(void)keycode;
	return (0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 300, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}


