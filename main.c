#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	int		l;
	float	f;
	char	*c;
	char	a;

	a = '3';
	c = "1";
	i = 0;
	l = 1;
	f= 343.1059884;
	printf("Hello %p worlde!\n", c);
	ft_printf("Hello %p worlde!\n", c);
	return (0);
}
