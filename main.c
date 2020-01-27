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
	i = -18;
	l = 18;
	printf("Hello %x world!\n", i);
	ft_printf("Hello %x world!\n", l);
	return (0);
}
