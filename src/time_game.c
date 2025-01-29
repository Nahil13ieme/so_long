/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:12 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 00:52:28 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/time_game.h"

static clock_t	g_last_frame_time = 0;

void	cap_fps(void)
{
	clock_t	current_time;
	clock_t	frame_time;

	current_time = clock();
	frame_time = (current_time - g_last_frame_time) * 1000 / CLOCKS_PER_SEC;
	if (frame_time < FRAME_TIME_MS)
	{
		usleep((FRAME_TIME_MS - frame_time) * 1000);
	}
	g_last_frame_time = clock();
}
