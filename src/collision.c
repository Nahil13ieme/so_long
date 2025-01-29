/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:35:26 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 00:53:23 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/collision.h"

int	is_colliding(t_box box1, t_box box2)
{
	if (box1.min.x < box2.max.x && box1.max.x > box2.min.x
		&& box1.min.y < box2.max.y && box1.max.y > box2.min.y)
		return (1);
	return (0);
}
