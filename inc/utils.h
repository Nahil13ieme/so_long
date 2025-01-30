/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:13 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:35 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "vector2d.h"

typedef struct s_game		t_game;
typedef struct s_sprite		t_sprite;
typedef struct s_level		t_level;
typedef struct s_dfs
{
	int			key_count;
	int			has_exit;
	t_vector2d	pos;
	t_vector2d	prev_pos;
	int			**visited;
}	t_dfs;

t_sprite	*draw_box(void *mlx, t_vector2d start, t_vector2d end);
void		draw_box_utils(t_sprite *sprite, int color);
int			dfs_layout(t_level level, t_dfs *dfs);

#endif //UTILS_H