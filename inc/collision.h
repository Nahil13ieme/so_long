/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:23:45 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:48:32 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "vector2d.h"

typedef struct s_box
{
	t_vector2d	min;
	t_vector2d	max;
}	t_box;

int	is_colliding(t_box box1, t_box box2);

#endif  //COLLISION_H