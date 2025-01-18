/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 07:14:32 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/17 10:55:26 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_logic.h"
#include "../minilibx-linux/mlx.h"
#include "texture.h"
#include <stdio.h>

void	load_texture(void *mlx, t_texture *texture, char *file_path)
{
	texture->img_ptr =  mlx_xpm_file_to_image(mlx, file_path, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		printf("no texture, exit.");
		exit(1);
	}
	texture->data_addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->line_len, &texture->endian);
}

void display_texture(t_vars vars, t_texture *texture, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, texture->img_ptr, x, y);
}

void display_sprite(t_vars vars, t_texture *texture, int sprite_width, int sprite_height, int sprite_index_x, int sprite_index_y, int dest_x, int dest_y)
{
	int	src_x = sprite_index_x * sprite_width;
	int	src_y = sprite_index_y * sprite_height;
	void *sprite_img;
	char *sprite_data;

	if (src_x + sprite_width > texture->width || src_y + sprite_height > texture->height) {
		printf("Sprite coordinates out of bounds.\n");
		return;
	}
	sprite_img = mlx_new_image(vars.mlx, sprite_width, sprite_height);
	sprite_data = mlx_get_data_addr(sprite_img, &texture->bpp, &texture->line_len, &texture->endian);
	for (int y = 0; y < sprite_height; y++) {
		for (int x = 0; x < sprite_width; x++) {
			int src_pixel = (src_y + y) * texture->line_len + (src_x + x) * (texture->bpp / 8);
			int dest_pixel = y * sprite_width * (texture->bpp / 8) + x * (texture->bpp / 8);
			*(unsigned int *)(sprite_data + dest_pixel) = *(unsigned int *)(texture->data_addr + src_pixel);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, sprite_img, dest_x, dest_y);
	mlx_destroy_image(vars.mlx, sprite_img);
}