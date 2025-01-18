/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:47:06 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/17 08:21:20 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOGIC_H
# define GAME_LOGIC_H

#include "texture.h"
#include <stdlib.h>

typedef struct s_pos
{
	int	x;
	int	y;
	int	z;
}	t_pos;

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

typedef struct s_player
{
	int					hp;
	int					is_dead;
	struct s_pos		pos;
	struct s_texture	texture;
}	t_player;

typedef struct s_game_object
{
	char				*type;
	struct s_pos		pos;
	struct s_texture	texture;
} t_game_object;

typedef struct s_game_context
{
	int						game_state;
	struct s_player			player;
	struct s_game_object	*game_objects;
	int						object_count;
} t_game_context;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;


void	init_game(void *mlx, t_game_context *game_context);
void	update();


#endif