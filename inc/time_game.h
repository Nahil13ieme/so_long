/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:19 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:56:07 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_GAME_H
# define TIME_GAME_H

# include <time.h>
# include <unistd.h>

# ifndef TARGET_FPS
#  define TARGET_FPS 60
# endif

enum e_fps
{
	FRAME_TIME_MS = (1000 / TARGET_FPS)
};

void	cap_fps(void);

#endif //TIME_GAME_H