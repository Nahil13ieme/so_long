/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:30:11 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/26 16:45:01 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct s_sprite
{
	void	*img_ptr;
	char	*buffer;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_sprite;

void	draw_sprite_to_buffer(t_sprite *buffer, t_sprite *sprite, int x_offset, int y_offset);

#endif //SPRITE_H