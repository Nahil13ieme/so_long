/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:28 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 14:21:16 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/vector2d.h"
#include "../inc/sprite.h"
#include "../inc/game.h"
/*
	Draw a box of size end - start. 
	It just return a t_sprite* but you need to draw it in render.c.
*/
t_sprite	*draw_box(void *mlx, t_vector2d start, t_vector2d end)
{
	t_sprite	*box;

	box = malloc(sizeof(t_sprite));
	if (!box)
		return NULL;
	box->width = end.x - start.x;
	box->height = end.y - start.y;
	box->img_ptr = mlx_new_image(mlx, box->width, box->height);
	if (!box->img_ptr)
	{
		free(box);
		return NULL;
	}
	box->buffer = mlx_get_data_addr(box->img_ptr, &box->bpp, &box->line_len, &box->endian);
	draw_box_utils(box, 0xFF0000);
	return (box);
}
/*
	Color : RGB (0XRRGGBB)
*/
void	draw_box_utils(t_sprite *sprite, int color)
{
	int	x;
	int	y;
	int	pixel_index;

	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			if (x == 0 || y == 0 || x == sprite->width -1 || y == sprite->height -1)
			{
				pixel_index = (y * sprite->line_len) + (x * (sprite->bpp / 8));
				*(unsigned int *)(sprite->buffer + pixel_index) = color;
			}
		}
	}
}

int	dfs_layout(t_level level, t_dfs *dfs)
{
	int			dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int			i;

	if (dfs->pos.x < 0 || dfs->pos.y < 0 || dfs->pos.x >= level.height || dfs->pos.y >= level.width)
		return (0);
	if (level.layout[dfs->pos.y][dfs->pos.x] == 'W' || dfs->visited[dfs->pos.y][dfs->pos.x])
		return (0);
	dfs->visited[dfs->pos.y][dfs->pos.x] = 1;
	if (level.layout[dfs->pos.y][dfs->pos.x] == 'E')
		dfs->has_exit = 1;
	if (level.layout[dfs->pos.y][dfs->pos.x] == 'K')
		dfs->key_count++;
	if (dfs->key_count == level.key_count && dfs->has_exit)
		return (1);
	i = -1;
	while (++i < 4)
	{
		dfs->pos.x += dir[i][0];
		dfs->pos.y += dir[i][1];
		if (dfs_layout(level, dfs))
			return (1);
		dfs->pos.x -= dir[i][0];
		dfs->pos.y -= dir[i][1];
	}
	return (0);
}
