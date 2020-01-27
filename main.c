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
	c = "agdf";
	i = 25;
	l = 1;
	printf("Hello %9s worlde\n", c);
	ft_printf("Hello %9s world!\n", c);
	return (0);
}
