/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:32:33 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/02 14:44:17 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*#include <stdlib.h>

int	main(void)
{
	char nptr[] = "  +4";
	char nptr1[] = "-21474  +83648";
	char nptr2[] = "21474q83648";
	char nptr3[] = "Q2147483647";
	char nptr4[] = "-4wadw";
	char nptr5[] = "--45";

	__builtin_printf("%d\n", ft_atoi(nptr));
	__builtin_printf("%d\n", ft_atoi(nptr1));
	__builtin_printf("%d\n", ft_atoi(nptr2));
	__builtin_printf("%d\n", ft_atoi(nptr3));
	__builtin_printf("%d\n", ft_atoi(nptr4));
	__builtin_printf("%d\n\n", ft_atoi(nptr5));

	__builtin_printf("True atoi : \n");
	__builtin_printf("%d\n", atoi(nptr));
	__builtin_printf("%d\n", atoi(nptr1));
	__builtin_printf("%d\n", atoi(nptr2));
	__builtin_printf("%d\n", atoi(nptr3));
	__builtin_printf("%d\n", atoi(nptr4));
	__builtin_printf("%d\n", atoi(nptr5));
	return (0);
}*/