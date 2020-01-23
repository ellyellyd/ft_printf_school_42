#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	unsigned int		i;
	char				*c;
	char				a;

	a = 'z';
	c = "a";
	i = -341;
	printf("Hello %o world!\n", i);
//	printf("%p\n%p\n", NULL, c);
	ft_printf("Hello %o world!\n", i);
	return (0);
}
