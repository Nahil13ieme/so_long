/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:21:10 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/27 19:21:11 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

typedef struct s_level
{
	char		**layout;
	int			width;
	int			height;
	int			is_done;
	t_entity	*entities;
}	t_level;


#endif //LEVEL_H