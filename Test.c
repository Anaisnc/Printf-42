#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void	courses(char *arg0, ...)
{
	va_list	ap;
	char	*cur_arg;
	int		i;
	int		nb_args;

	cur_arg = arg0;
	if (arg0 == NULL)
	{
		ft_putstr_fd("null\n", 1);
		return ;
	}
	va_start(ap, arg0);
	i = 1;
	nb_args = 0;
	while (i < nb_args)
	{
		if (i == nb_args - 1)
			ft_putstr_fd(" and ", 1);
		else
			ft_putstr_fd(", ", 1);
		printf("%s", va_arg(ap, char *));
		i++;
	}
	ft_putstr_fd("\n", 1);
	va_end(ap);
}

int	main(int argc, char *argv[])
{

}