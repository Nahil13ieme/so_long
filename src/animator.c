/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:18:44 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 14:53:36 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void	free_animator(t_animator *animator)
{
	if (animator)
	{
		if (animator->animations)
			free(animator->animations);
		free(animator);
	}
}