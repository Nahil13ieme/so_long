/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:18 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 11:53:59 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/entity.h"
#include "../inc/sprite.h"

void	init_entity()
{
	t_entity entity;
	
	entity.sprite = new_sprite();
}