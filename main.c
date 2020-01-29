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
	f = 343.1059884;
	printf("Hello %i worlde!\n", i);
	ft_printf("Hello %i worlde!\n\n", i);

	printf("Hello % i worlde!\n", i);
	ft_printf("Hello % i worlde!\n\n", i);

	printf("Hello %+i worlde!\n", i);
	ft_printf("Hello %+i worlde!\n\n", i);

	printf("Hello %2i worlde!\n", i);
	ft_printf("Hello %2i worlde!\n\n", i);

	printf("Hello % 2i worlde!\n", i);
	ft_printf("Hello % 2i worlde!\n\n", i);

	printf("Hello %02i worlde!\n", i);
	ft_printf("Hello %02i worlde!\n\n", i);

	printf("Hello %-i worlde!\n", i);
	ft_printf("Hello %-i worlde!\n\n", i);

	printf("Hello %-2i worlde!\n", i);
	ft_printf("Hello %-2i worlde!\n\n", i);

	printf("Hello %+-2i worlde!\n", i);
	ft_printf("Hello %+-2i worlde!\n\n", i);

	printf("Hello %+-i worlde!\n", i);
	ft_printf("Hello %+-i worlde!\n\n", i);

	printf("Hello %+2i worlde!\n", i);
	ft_printf("Hello %+2i worlde!\n\n", i);

	printf("Hello % 02i worlde!\n", i);
	ft_printf("Hello % 02i worlde!\n\n", i);

	printf("Hello % -2i worlde!\n", i);
	ft_printf("Hello % -2i worlde!\n", i);
	return (0);
}
