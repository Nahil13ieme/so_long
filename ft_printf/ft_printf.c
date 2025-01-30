/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:35:52 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:22:28 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	params;
	size_t	written_char;

	va_start(params, format);
	written_char = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			written_char += ft_check_format(*format, params);
		}
		else
		{
			ft_putchar(*format, 1);
			written_char++;
		}
		format++;
	}
	va_end(params);
	return (written_char);
}
