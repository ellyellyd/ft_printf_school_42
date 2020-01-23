#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	char	*c;
	char	a;

	a = 'z';
	c = "a";
	i = -1;
	printf("Hello %u world!\n", i);
//	printf("%p\n%p\n", NULL, c);
	ft_printf("Hello %u world!\n", i);
	return (0);
}
