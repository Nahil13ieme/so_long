/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:46:54 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 18:22:10 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_logic.h"


void	init_game(void *mlx, t_game_context *game_context)
{
	game_context->game_state = 0;
	init_player(&game_context->player, (t_pos){0, 0, 1}, (t_texture){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

	game_context->object_count = 0;
	game_context->game_objects = malloc(sizeof(t_game_object) * 10);
	new_texture(mlx, &game_context->game_objects[0].texture, 400, 300);
	game_context->game_objects[0].object_type = WALL;
	load_texture(mlx, &game_context->player.texture, game_context->player.texture.file_path);
}
int	handle_input(int keycode, t_game_context *game_context) 
{
	if (keycode == KEY_ESC)
	{
		free_game(game_context);
		mlx_destroy_window(game_context->vars.mlx, game_context->vars.win);
		exit(0);
	}
	if (keycode == KEY_W)
		move_player(&game_context->player, game_context, 0, -10);
	if (keycode == KEY_A)
		move_player(&game_context->player, game_context, -10, 0);
	if (keycode == KEY_D)
		move_player(&game_context->player, game_context, 10, 0);
	if (keycode == KEY_S)
		move_player(&game_context->player, game_context, 0, 10);
	return (0);
}

void	create_game_objects(t_game_context *game_context, t_texture texture)
{
	int	i;

	i = 0;
	while (i < game_context->object_count)
	{
		if (&game_context->game_objects[i].type == NULL)
		{
			if (texture.file_path == NULL)
			{
				new_texture(game_context->vars.mlx, &game_context->game_objects[i].texture, 1, 1);
				game_context->game_objects[i].object_type = WALL;
			}
		}
	}
}

void	extract_map_from_file(char *file_path, t_game_context *game_context)
{
	// open file
	(void)file_path;
	(void)game_context;
	// read file
	// extract map
	// store map in game_context
}

int	game_loop(t_game_context *game_context)
{
	put_pixel_img(game_context->game_objects[0].texture, 150, 150, 0xFFFFFFFF);
	display_texture(game_context->vars, &game_context->player.texture, game_context->player.pos.x, game_context->player.pos.y);
	display_texture(game_context->vars, &game_context->game_objects[0].texture, 0, 0);
	return (1);
}

void free_game(t_game_context *game_context)
{
	free(game_context->game_objects);
}