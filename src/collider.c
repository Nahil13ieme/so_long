/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:15:37 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 16:55:59 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"

int	is_colliding(t_pos pos, t_box hitbox)
{
	if (pos.x < hitbox.min.x || pos.x > hitbox.max.x)
		return (0);
	if (pos.y < hitbox.min.y || pos.y > hitbox.max.y)
		return (0);
	return 1;
}