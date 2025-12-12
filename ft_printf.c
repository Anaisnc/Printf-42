/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/12 17:09:51 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*#include <stdio.h>

int	main(void)
{
	int				c = 'a';
	const char		*s = "hello";
	void			*p = "-2147483648";
	int				d = -2147483648;
	int				i = -2147483648;
	unsigned int	u = -2147483648;
	unsigned int	x = -2147483648;
	unsigned int	X = -2147483648;

	int res1 = ft_printf("hello %% \n %c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n", c, s, p, d, i, u, x, X);
	printf("%d\n", res1);

	int res2 = printf("hello %% \n %c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n", c, s, p, d, i, u, x, X);
	printf("%d\n", res2);

	int res1 = ft_printf("%%");
	printf("%d\n", res1);

	int res2 = printf("%%");
	printf("%d\n", res2);
	
	return (0);
}*/
