/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:14:12 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/19 11:13:00 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

#include "game_logic.h"
typedef struct s_vars t_vars;

typedef struct s_texture
{
	void	*img_ptr;
	char	*data_addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*file_path;
} t_texture;

void	new_texture(void *mlx, t_texture *img, int width, int height);
void	load_texture(void *mlx, t_texture *texture, char *file_path);
void	display_texture(t_vars vars, t_texture *texture, int x, int y);
void	display_image(t_vars vars, t_texture *img, int x, int y);
void	put_pixel_img(t_texture img, int x, int y, int color);
// void	display_sprite(t_vars vars, t_texture *texture, int sprite_width, int sprite_height, int sprite_index_x, int sprite_index_y, int dest_x, int dest_y);

#endif