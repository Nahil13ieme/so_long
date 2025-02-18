/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:50:49 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:46:10 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sprite.h"
#include "../inc/game.h"
#include "../Libft/libft.h"
#include <stdlib.h>

void	free_sprite_manager(t_game *game)
{
	if (game->s_manager->wall)
		mlx_destroy_image(game->vars.mlx, game->s_manager->wall->img_ptr);
	if (game->s_manager->exit)
		mlx_destroy_image(game->vars.mlx, game->s_manager->exit->img_ptr);
	if (game->s_manager->key)
		mlx_destroy_image(game->vars.mlx, game->s_manager->key->img_ptr);
	if (game->s_manager->player)
		mlx_destroy_image(game->vars.mlx, game->s_manager->player->img_ptr);
	free(game->s_manager->wall);
	free(game->s_manager->exit);
	free(game->s_manager->key);
	free(game->s_manager->player);
	free(game->s_manager);
}

t_sprite_manager	*init_sprite_manager(t_game	*game)
{
	t_sprite_manager	*tmp;

	tmp = malloc(sizeof(t_sprite_manager));
	if (!tmp)
		free_errors(game, SPRITE_MANAGER_NOT_LOADED);
	tmp->exit = new_sprite(game->vars.mlx, "img/exit.xpm");
	tmp->wall = new_sprite(game->vars.mlx, "img/wall.xpm");
	tmp->key = new_sprite(game->vars.mlx, "img/key.xpm");
	tmp->player = new_sprite(game->vars.mlx, "img/idle.xpm");
	if (!tmp->exit || !tmp->wall || !tmp->key || !tmp->player)
	{
		game->s_manager = tmp;
		free_errors(game, SPRITE_MANAGER_NOT_FULLY_LOADED);
	}
	return (tmp);
}

void	draw_sprite_to_buffer(t_sprite *buffer, t_sprite *sprite, int x_offset,
	int y_offset)
{
	int				y;
	int				x;
	char			*src_pixel;
	unsigned int	color;
	char			*dst_pixel;

	if (!buffer->buffer || !sprite->buffer)
		return ;
	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			src_pixel = sprite->buffer
				+ ((y * sprite->line_len) + (x * (sprite->bpp / 8)));
			color = *(unsigned int *)src_pixel;
			if (color && color != 0xFF000000)
			{
				dst_pixel = buffer->buffer + ((y + y_offset) * buffer->line_len
						+ (x + x_offset) * (buffer->bpp / 8));
				*(unsigned int *)dst_pixel = color;
			}
		}
	}
}

t_sprite	*new_sprite(void *mlx, char *filepath)
{
	t_sprite	*tmp;

	tmp = malloc(sizeof(t_sprite));
	if (!tmp)
		return (NULL);
	tmp->img_ptr = mlx_xpm_file_to_image(mlx, filepath,
			&tmp->width, &tmp->height);
	if (!tmp->img_ptr)
	{
		free(tmp);
		return (NULL);
	}
	tmp->buffer = mlx_get_data_addr(tmp->img_ptr,
			&tmp->bpp, &tmp->line_len, &tmp->endian);
	if (!tmp->buffer)
	{
		mlx_destroy_image(mlx, tmp->img_ptr);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
