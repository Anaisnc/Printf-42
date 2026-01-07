/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/07 18:49:18 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_display_arg(va_list list, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(list, const char *)));
	if (c == 'p')
		return (ft_print_base_void((unsigned long)va_arg(list, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (ft_print_base(va_arg(list, unsigned int), "0123456789", 10));
	if (c == 'x')
		return ((ft_print_base(va_arg(list, unsigned int), "0123456789abcdef",
					16)));
	if (c == 'X')
		return ((ft_print_base(va_arg(list, unsigned int), "0123456789ABCDEF",
					16)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	size_t	i;
	va_list	list;

	if (!format)
		return (-1);
	va_start(list, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_display_arg(list, format[i + 1]);
			i = i + 2;
		}
		else
		{
			len += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(list);
	return (len);
}
