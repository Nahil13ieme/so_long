/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:18:40 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/20 08:26:51 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATOR_H
# define ANIMATOR_H

typedef struct s_animation
{
	int		frame_count;
	int		current_frame;
	int		frame_duration;
	int		current_frame_duration;
}	t_animation;

typedef struct s_animator
{
	t_animation	*animations;
	int			animation_count;
}	t_animator;

void	init_animator(t_animator *animator, int animation_count);
void	init_animation(t_animation *animation, int frame_count, int frame_duration);
void	update_animation(t_animation *animation);
void	update_animator(t_animator *animator);
void	free_animator(t_animator *animator);

#endif