/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:36:05 by oharoon           #+#    #+#             */
/*   Updated: 2022/11/18 11:08:38 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	int		size;
	va_list	tab;

	va_start(tab, format);
	count = -1;
	size = 0;
	while (format[++count])
	{
		if (format[count] == '%')
		{
			size += string_handle(format[++count], &tab);
		}
		else
			size += write(1, &format[count], 1);
	}
	va_end(tab);
	return (size);
}
