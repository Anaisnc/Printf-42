/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:34:30 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/12 15:31:19 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	fr_print_base(unsigned int n, char *base, unsigned int base_len);
int	fr_print_base_void(unsigned long nb);
int	ft_display_arg(va_list list, char c);
int	ft_printf(const char *format, ...);

#endif