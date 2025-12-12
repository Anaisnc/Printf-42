/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/12 15:30:50 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//le cas ou y a une lettre derriere le % autre que celles demandées
int	ft_display_arg(va_list list, char c)
{
	if (c == '%')
		ft_putchar('%');
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(list, const char *)));
	if (c == 'p')
		return ((fr_print_base_void(va_arg(list, unsigned long))));
	if (c == 'd')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (fr_print_base(va_arg(list, unsigned int), "0123456789", 10));
	if (c == 'x')
		return ((fr_print_base(va_arg(list, unsigned int), "0123456789abcdef",
					16)));
	if (c == 'X')
		return ((fr_print_base(va_arg(list, unsigned int), "0123456789ABCDEF",
					16)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	size_t	i;
	va_list	list;

	va_start(list, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_display_arg(list, format[i + 1]);
			i = i + 2;
		}
		len += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (len);
}


#include <stdio.h>

int	main(void)
{
	/*int				c;
	const char		*s = "hello";*/
	void			*p;
	/*int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;*/

	//c = 'a';
	p = "214748364";
	/*d = -2147483648;
	i = -2147483648;
	u = -2147483648;
	x = -2147483648;
	X = -2147483648;*/

	int res1 = ft_printf("%p", p);
	printf("%d\n", res1);
	
	return (0);
}
