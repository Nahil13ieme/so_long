/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:39:32 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/19 10:36:39 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "keycode.h"

int main(void)
{
	t_vars			vars;
	t_game_context	game_context;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	printf("vars mlx initialized\n");
	vars.win = mlx_new_window(vars.mlx, 400, 300, "Hello world!");
	if (!vars.win)
		return (1);
	printf("vars win initialized\n");
	init_game(vars.mlx, &game_context);
	game_context.vars = vars;
	printf("game initialized\n");
	mlx_hook(vars.win, 2, 1L << 0, handle_input, &game_context);
	mlx_loop_hook(vars.mlx, game_loop, &game_context);
	mlx_loop(vars.mlx);
	return (0);
}