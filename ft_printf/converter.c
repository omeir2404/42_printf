/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:26:16 by oharoon           #+#    #+#             */
/*   Updated: 2022/11/18 04:15:00 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converter(double nbr, char *base, double size)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= size)
		count += converter(nbr / size, base, size);
	count += write(1, &base[((unsigned long) nbr) % ((unsigned long)size)], 1);
	return (count);
}

int	converter_ptr(unsigned long nbr, char *base, unsigned long size)
{
	int		count;

	count = 0;
	if (nbr >= size)
		count += converter_ptr(nbr / size, base, size);
	count += write(1, &base[nbr % size], 1);
	return (count);
}
