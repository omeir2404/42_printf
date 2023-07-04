/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:15:22 by oharoon           #+#    #+#             */
/*   Updated: 2022/11/18 11:07:31 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_handle(char c, va_list	*args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (pointerhandle(va_arg(*args, unsigned long)));
	if (c == 'i' || c == 'd')
		return (converter(va_arg(*args, int), "0123456789", 10));
	if (c == 'u')
		return (converter(va_arg(*args, unsigned int), "0123456789", 10));
	if (c == 'x')
		return (converter(va_arg(*args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (converter(va_arg(*args, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}
