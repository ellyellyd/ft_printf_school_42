#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	int		l;
	char	*c;
	char	a;

	a = '3';
	c = "argfjdbgdf";
	i = 1;
	l = 118;
	printf("Hello %9u worlde\n", l);
	ft_printf("Hello %9u world!\n", l);
	return (0);
}
