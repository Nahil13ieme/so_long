/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:34:22 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/30 18:22:14 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../Libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_check_format(char c, va_list args);
int	ft_putstr(char *str, int fd);
int	ft_putchar(char c, int fd);

#endif