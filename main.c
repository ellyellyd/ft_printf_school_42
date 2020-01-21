#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	char	*c;
	char	a;

	a = 's';
	c = "dgd";
	i = -2;
	printf("#Hello %u world!\n", i);
	ft_printf("#Hello %u world!\n", i);
	return (0);
}
