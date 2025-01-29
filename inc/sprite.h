/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:30:11 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 18:09:52 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

#include "../minilibx-linux/mlx.h"

typedef struct s_game	t_game;

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

typedef struct s_sprite_manager
{
	t_sprite	*wall;
	t_sprite	*key;
	t_sprite	*exit;
	t_sprite	*player;
}	t_sprite_manager;

t_sprite_manager	*init_sprite_manager(t_game	*game);
void				free_sprite_manger(t_game *game);
void				draw_sprite_to_buffer(t_sprite *buffer, t_sprite *sprite, int x_offset, int y_offset);
t_sprite			*new_sprite(void *mlx, char *filepath);

#endif //SPRITE_H