/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:50:49 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 16:45:07 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sprite.h"
#include "../inc/game.h"
#include "../Libft/libft.h"
#include <stdlib.h>

void	free_sprite_manger(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->s_manager->wall->img_ptr);
	mlx_destroy_image(game->vars.mlx, game->s_manager->exit->img_ptr);
	mlx_destroy_image(game->vars.mlx, game->s_manager->key->img_ptr);
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
		return (NULL);
	tmp->exit = new_sprite(game->vars.mlx, "img/exit.xpm");
	tmp->wall = new_sprite(game->vars.mlx, "img/wall.xpm");
	tmp->key = new_sprite(game->vars.mlx, "img/key.xpm");
	tmp->player = new_sprite(game->vars.mlx, "img/idle.xpm");
	if (!tmp->exit || !tmp->wall || !tmp->key)
		return (NULL);
	return (tmp);
}

void draw_sprite_to_buffer(t_sprite *buffer, t_sprite *sprite, int x_offset, int y_offset)
{
	int				y = 0;
	int				x = 0;
	char			*src_pixel;
	unsigned int	color;
	char			*dst_pixel;

	if (!buffer->buffer || !sprite->buffer)
		return ;	
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			src_pixel = sprite->buffer + (y * sprite->line_len + x * (sprite->bpp / 8));
			color = *(unsigned int *)src_pixel;
			if (color != 0xFF000000)
			{
				dst_pixel = buffer->buffer + ((y + y_offset) *
					buffer->line_len + (x + x_offset) * (buffer->bpp / 8));
				*(unsigned int *)dst_pixel = color;
			}
			x++;
		}
		y++;
	}
}

t_sprite	*new_sprite(void *mlx, char *filepath)
{
	t_sprite	*tmp;

	tmp = malloc(sizeof(t_sprite));
	tmp->line_len = 0;
	tmp->bpp = 0;
	tmp->endian = 0;
	if (!tmp)
		return (NULL);
	tmp->img_ptr = mlx_xpm_file_to_image(mlx, filepath, &tmp->width, &tmp->height);
	if (!tmp->img_ptr)
	{
		free(tmp);
		return (NULL);
	}
	tmp->buffer = mlx_get_data_addr(tmp->img_ptr, &tmp->bpp, &tmp->line_len, &tmp->endian);
	if (!tmp->buffer)
	{
		mlx_destroy_image(mlx, tmp->img_ptr);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
