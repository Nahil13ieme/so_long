/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:28 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 19:03:52 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/vector2d.h"
#include "../inc/sprite.h"
#include "../inc/game.h"

t_sprite *draw_box(t_game *game, t_vector2d start, t_vector2d end)
{
	t_sprite	*box = malloc(sizeof(t_sprite));
	int			x;
	int			y;
	int			color = 0xFF0000;
	if (!box)
		return NULL;
	box->width = end.x - start.x;
	box->height = end.y - start.y;
	box->img_ptr = mlx_new_image(game->vars.mlx, box->width, box->height);
	if (!box->img_ptr)
	{
		free(box);
		return NULL;
	}
	box->buffer = mlx_get_data_addr(box->img_ptr, &box->bpp, &box->line_len, &box->endian);
	for (y = 0; y < box->height; y++)
	{
		for (x = 0; x < box->width; x++)
		{
			if (x == 0 || y == 0 || x == box->width -1 || y == box->height -1)
			{
				int pixel_index = (y * box->line_len) + (x * (box->bpp / 8));
				*(unsigned int *)(box->buffer + pixel_index) = color;
			}
		}
	}
	return box;
}
