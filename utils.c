/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:21:50 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/16 15:51:47 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
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
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}

int	ft_print_base(unsigned long n, char *base, unsigned long base_len)
{
	int	count;

	count = 0;
	if (n >= base_len)
	{
		count += ft_print_base(n / base_len, base, base_len);
		count += ft_print_base(n % base_len, base, base_len);
	}
	else
		count += write(1, &base[n], 1);
	return (count);
}

int	ft_print_base_void(unsigned long nb)
{
	int	count;

	if (!nb)
		return (write(1, "(nil)", 5));
	count = 2;
	write(1, "0x", 2);
	count += ft_print_base(nb, "0123456789abcdef", 16);
	return (count);
}
