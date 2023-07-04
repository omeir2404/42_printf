/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:43:07 by oharoon           #+#    #+#             */
/*   Updated: 2022/11/18 04:12:56 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *printed, ...);
int			string_handle(char c, va_list *args);
int			pointerhandle(unsigned long int nb);
size_t		ft_strlen(const char *str);
int			converter(double nbr, char *base, double size);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			converter_ptr(unsigned long nbr, char *base, unsigned long size);

#endif