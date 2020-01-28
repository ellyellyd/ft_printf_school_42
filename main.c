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
	printf("Hello %-#9o worlde\n", i);
	ft_printf("Hello %-#9o worlde!\n", i);
	return (0);
}
