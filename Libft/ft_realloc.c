/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:37:22 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/28 10:18:22 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*ret;
	
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		ret = malloc(new_size);
		return (ret);
	}
	ret = malloc(new_size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, ptr, new_size);
	free(ptr);
	return (ret);
}