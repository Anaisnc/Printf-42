/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/10 15:01:16 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	return (write(1, &a, 1));
}
int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}

int	fr_print_base(unsigned int n, char *base, unsigned int base_len)
{
	int	count;

	count = 0;
	if (n >= base_len)
	{
		fr_print_base(n / base_len, base, base_len);
		fr_print_base(n % base_len, base, base_len);
	}
	else
		count += write(1, &base[n], 1);
	return (count);
}
int	fr_print_base_void(unsigned long nb)
{
	int	count;
	
	count = 2;
	write(1, "0x", 2);
	count += fr_print_base(nb, "0123456789abcdef", 16);
	return (count);
}

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

int	main(void)
{
	int				c;
	const char		*s = "hello";
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;

	c = 'a';
	p = "214748364";
	d = -2147483648;
	i = -2147483648;
	u = -2147483648;
	x = -2147483648;
	X = -2147483648;
	ft_printf("format: hello\n %% = %%\n c = %c\n s = %s\n p = %p\n d = %d\n i = %i\n u = %u\n x = %x\n X = %X\n", c, s, p, d, i, u, x, X);
	int result = ft_printf("format: hello\n %% = %%\n c = %c\n s = %s\n p = %p\n d = %d\n i = %i\n u = %u\n x = %x\n X = %X\n", c, s, p, d, i, u, x, X);
	ft_printf("result: %d\n", result);
	int result2 = printf("format: hello\n %% = %%\n c = %c\n s = %s\n p = %p\n d = %d\n i = %i\n u = %u\n x = %x\n X = %X\n", c, s, p, d, i, u, x, X);
	printf("format: hello\n %% = %%\n c = %c\n s = %s\n p = %p\n d = %d\n i = %i\n u = %u\n x = %x\n X = %X\n", c, s, p, d, i, u, x, X);
	printf("result2: %d\n", result2);
	return (0);
}
