/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:06 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 16:28:53 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef struct s_game	t_game;

typedef enum e_errors
{
	GAME_NOT_LOADED,
	MLX_NOT_LOADED,
	WIN_NOT_LOADED,
	MAIN_BUFFER_IMG_PTR_NOT_LOADED,
	MAIN_BUFFER_NOT_LOADED,
	SPRITE_MANAGER_NOT_LOADED,
	SPRITE_MANAGER_NOT_FULLY_LOADED,
	FD_NOT_OPEN,
	LEVEL_NOT_LOADED
} t_errors;

void	free_errors(t_game *game, int i);
void	free_all(t_game *game);
#endif //ERRORS_H