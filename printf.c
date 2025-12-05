/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:15:53 by ancourt           #+#    #+#             */
/*   Updated: 2025/12/05 19:35:15 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*returns the number of characters printed after successful execution
error : return a negative value
... = the variables/values corresponding to the format specifier
const char	* = a string that specifies the data to be printedm may contain a
format specifier.*/

#include "printf.h"
#include <stdarg.h>

/*exemple printf = printf("hello %d the world", nb); printf ("%s\n", "Hello world");
parcourir la string donnée et trouver tous les %
quand on trouver un % on va l'ajouter a notre liste*/

/*arg0 = premier element de la liste.*/
/*void	list_arg(char *arg0, ...)
{
	va_list	list;
	size_t	nb_arg;
	char	*current_arg;

	current_arg = arg0;
	va_start(list, arg0);
	nb_arg = 0;
	while (current_arg)
	{
		current_arg = va_arg(list, char *);
		nb_arg++;
	}
	va_end(list);
}*/

//function to display the arguments
//c = the letter after % = cspdiuxX%
void	ft_display_arg(void *arg, char c)
{
	if (c == 'c')
		ft_putchar_fd(arg, 1);
	if (c == 's')
		ft_putchar_fd(arg, 1);
	if (c == 'p')
	
	if (c == 'd')
		ft_putnbr_fd(arg, 1);
	if (c == 'i')
	
	if (c == 'u')
	
	if (c == 'x')
	
	if (c == 'X')
	
}


int	ft_printf(const char *arg0, ...)
{
	int	len;
	va_list	list;
	
	va_start(list, *arg0);
	va_arg(list, char *);
	va_end(list);
	len = ft_strlen(arg0); //pas comme ca, parser la string d'abord
	ft_putstr_fd(arg0, 1);
	return (len);
}


int	main(void)
{
	const char	*s = "hello";

	ft_printf(s);
}
