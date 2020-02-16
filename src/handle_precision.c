#include "libftprintf.h"

void	handle_precision(t_frm *tmp, int len)
{
	int		i;

	i = 0;
	while (i < (tmp->precision - len))
	{
		putchar_and_count('0', tmp);
		i += 1;
	}
}
