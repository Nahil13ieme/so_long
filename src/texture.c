/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 07:14:32 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/19 10:57:30 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_logic.h"
#include "../minilibx-linux/mlx.h"
#include "texture.h"
#include <stdio.h>

void	new_texture(void *mlx, t_texture *texture, int width, int height)
{
	texture->img_ptr = mlx_new_image(mlx, width, height);
	texture->data_addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->line_len, &texture->endian);
	texture->width = width;
	texture->height = height;
}

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

void	display_texture(t_vars vars, t_texture *texture, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, texture->img_ptr, x, y);
}

void	put_pixel_img(t_texture texture, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < texture.width && y < texture.height) {
		dst = texture.data_addr + (y * texture.line_len + x * (texture.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
