/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:10 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 16:27:11 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

#include "../Libft/libft.h"
#include "../gnl_bonus/get_next_line.h"
#include "../inc/vector2d.h"

typedef struct s_game		t_game;
typedef struct s_entity		t_entity;
typedef struct s_sprite		t_sprite;
typedef struct s_dfs		t_dfs;

typedef struct s_level
{
	char		**layout;
	int			width;
	int			height;
	int			is_done;
	int			has_player;
	int			has_exit;
	int			entities_count;
	int			key_count;
	t_entity	*entities;
	t_vector2d	start;
	t_vector2d	*keys;
	t_vector2d	end;
}	t_level;

void	free_dfs(t_dfs *dfs, t_level level);
int		check_dfs(t_level level);
void	init_level(t_game *game);
void	init_level_2(t_game *game);
t_level	parse_level_info(int fd);
void	add_entities(t_game *game, t_level *level);
#endif //LEVEL_H