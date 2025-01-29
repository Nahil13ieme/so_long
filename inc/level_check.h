/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:54:35 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/29 16:38:51 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_CHECK_H
# define LEVEL_CHECK_H

typedef struct s_level	t_level;
typedef struct s_game	t_game;

int		check_level_info(t_level *level);
int		check_borders(int i, int j, char c, t_level *level);
int		check_unique_entities(char c, t_level *level);
void	check_key_looted(t_game *game);

#endif //LEVEL_CHECK_H