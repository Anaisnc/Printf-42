/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/05 09:14:35 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_arg(va_list list, char c)
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

	va_start(list, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (-1);
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
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h" 

int	main(void)
{
	int	original;
	int	crafted;

	char	*str = "Hello world";
	char	*empty_str = "";
	char	*null_str = NULL;
	void	*ptr = str;
	void	*null_ptr = NULL;
	int	n = 12;
	int	neg = -12;
	int	zero = 0;
	unsigned int u = 12;
	unsigned int u_large = 4294967295u;

	original = printf("%s %s %s\n", str, empty_str, null_str);
	crafted = printf("%s %s %s\n", str, empty_str, null_str);
	printf("%d | %d\n\n", original, crafted);

	original = printf("%d %d %d\n", n, neg, zero);
    crafted = ft_printf("%d %d %d\n\n", n, neg, zero);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%u %u\n", u, u_large);
    crafted = ft_printf("%u %u\n\n", u, u_large);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%x %X\n", u_large, u_large);
    crafted = ft_printf("%x %X\n\n", u_large, u_large);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%p %p\n", ptr, null_ptr);
    crafted = ft_printf("%p %p\n\n", ptr, null_ptr);
    printf("%d | %d\n\n", original, crafted);

	original = printf("%%\n");
    crafted = ft_printf("%%\n\n");
    printf("%d | %d\n\n", original, crafted);

    return (0);
}