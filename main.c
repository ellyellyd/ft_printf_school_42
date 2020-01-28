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
	c = "agdfee";
	i = 0;
	l = 1;
	printf("Hello %x world!\n", i);
	ft_printf("Hello %x world!\n", i);
	return (0);
}
