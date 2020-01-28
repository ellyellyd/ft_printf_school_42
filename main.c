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
	i = -21;
	l = 1;
	printf("Hello %i world!\n", i);
	ft_printf("Hello %i world!\n", i);
	return (0);
}
