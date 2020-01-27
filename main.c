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
	l = 18;
	printf("Hello %+100i world!\n", l);
	ft_printf("Hello %+100i world!\n", l);
	return (0);
}
