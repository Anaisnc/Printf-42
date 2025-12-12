/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:21:50 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/12 17:09:56 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
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
		count += fr_print_base(n / base_len, base, base_len);
		count += fr_print_base(n % base_len, base, base_len);
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

