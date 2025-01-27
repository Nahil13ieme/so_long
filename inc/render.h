/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:36:18 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/26 19:10:33 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "sprite.h"
#include "../minilibx-linux/mlx.h"

# define WIN_W 800
# define WIN_H 600

typedef struct s_game		t_game;
typedef struct s_sprite		t_sprite;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	init_window(t_game *game);
void	init_renderer(t_game *game);
void	clear_display(t_game *game);
int		init_texture(t_game *game);
void	render(t_game *game);

#endif //RENDER_H