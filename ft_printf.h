/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:34:30 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/16 15:51:42 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_print_base_void(unsigned long nb);
int	ft_print_base(unsigned long n, char *base, unsigned long base_len);
int	ft_display_arg(va_list list, char c);
int	ft_printf(const char *format, ...);

#endif