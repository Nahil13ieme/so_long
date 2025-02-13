/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:15:28 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/13 03:41:43 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/vector2d.h"
#include "../inc/sprite.h"
#include "../inc/game.h"
/*
	Draw a box of size end - start. 
	It just return a t_sprite* you need to draw it in render.c.
*/
t_sprite	*draw_box(void *mlx, t_vector2d start, t_vector2d end)
{
	t_sprite	*box;

	box = malloc(sizeof(t_sprite));
	if (!box)
		return (NULL);
	box->width = end.x - start.x;
	box->height = end.y - start.y;
	box->img_ptr = mlx_new_image(mlx, box->width, box->height);
	if (!box->img_ptr)
	{
		free(box);
		return (NULL);
	}
	box->buffer = mlx_get_data_addr(box->img_ptr, &box->bpp,
			&box->line_len, &box->endian);
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
			if (x == 0 || y == 0 || x == sprite->width -1
				|| y == sprite->height -1)
			{
				pixel_index = (y * sprite->line_len) + (x * (sprite->bpp / 8));
				*(unsigned int *)(sprite->buffer + pixel_index) = color;
			}
		}
	}
}

void	free_dfs(t_dfs *dfs, t_level level)
{
	int	i;

	i = -1;
	while (++i < level.width)
		if (dfs->visited[i])
			free(dfs->visited[i]);
	free(dfs->visited);
	free(dfs);
}

int	init_dfs(t_dfs *dfs, t_level level)
{
	int	i;

	dfs->pos = level.start;
	dfs->prev_pos = dfs->pos;
	dfs->dir[0][0] = 0;
	dfs->dir[0][1] = 1;
	dfs->dir[1][0] = 0;
	dfs->dir[1][1] = -1;
	dfs->dir[2][0] = 1;
	dfs->dir[2][1] = 0;
	dfs->dir[3][0] = -1;
	dfs->dir[3][1] = 0;
	dfs->visited = malloc(sizeof(int *) * level.width);
	if (!dfs->visited)
		return (free(dfs), 0);
	i = -1;
	while (++i < level.width)
	{
		dfs->visited[i] = malloc(sizeof(int) * level.height);
		if (!dfs->visited[i])
			return (free_dfs(dfs, level), 0);
		ft_memset(dfs->visited[i], 0, level.height * sizeof(int));
	}
	return (1);
}

int	dfs_layout(t_level level, t_dfs *dfs)
{
	int			i;

	if (dfs->pos.x < 0 || dfs->pos.y < 0 || dfs->pos.x >= level.height
		|| dfs->pos.y >= level.width
		|| level.layout[dfs->pos.y][dfs->pos.x] == 'W'
		|| dfs->visited[dfs->pos.y][dfs->pos.x])
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
		dfs->pos.x += dfs->dir[i][0];
		dfs->pos.y += dfs->dir[i][1];
		if (dfs_layout(level, dfs))
			return (1);
		dfs->pos.x -= dfs->dir[i][0];
		dfs->pos.y -= dfs->dir[i][1];
	}
	return (0);
}
