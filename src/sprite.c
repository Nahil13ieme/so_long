/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:50:49 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:54:28 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sprite.h"

void draw_sprite_to_buffer(t_sprite *buffer, t_sprite *sprite, int x_offset, int y_offset)
{
	int y = 0;
	int x = 0;
	char *src_pixel;
	unsigned int color;
	char *dst_pixel;

	if (!buffer->buffer || !sprite->buffer)
		return ;
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			src_pixel = sprite->buffer + (y * sprite->line_len + x * (sprite->bpp / 8));
			color = *(unsigned int *)src_pixel;
			if (color != 0xFF000000)
			{
				dst_pixel = buffer->buffer + ((y + y_offset) * buffer->line_len + (x + x_offset) * (buffer->bpp / 8));
				*(unsigned int *)dst_pixel = color;
			}
			x++;
		}
		y++;
	}
}

t_sprite	new_sprite(char *filepath)
{
	
}
