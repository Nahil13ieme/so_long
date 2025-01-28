/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:19 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 16:57:53 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

#include <time.h>
#include <unistd.h>

# define TARGET_FPS 60
# define FRAME_TIME_MS (1000 / TARGET_FPS)


void	cap_fps(void);


#endif //TIME_H