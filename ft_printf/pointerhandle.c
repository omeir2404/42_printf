/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerhandle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:19:23 by oharoon           #+#    #+#             */
/*   Updated: 2022/11/18 04:19:50 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointerhandle(unsigned long int nb)
{
	if (nb == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + converter_ptr(nb, "0123456789abcdef", 16));
}
