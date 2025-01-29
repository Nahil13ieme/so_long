/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:13 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 19:01:21 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_game		t_game;
typedef struct s_vector2d	t_vector2d;
typedef struct s_sprite		t_sprite;

t_sprite	*draw_box(t_game *game, t_vector2d start, t_vector2d end);

#endif //UTILS_H