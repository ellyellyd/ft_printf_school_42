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
	i = -8;
	l = 8;
	printf("Hello %060u world!\n", i);
	ft_printf("Hello %u world!\n", l);
	return (0);
}
