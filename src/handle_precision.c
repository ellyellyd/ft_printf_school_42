#include "libftprintf.h"

void	handle_precision(t_frm *tmp)
{
	int		i;

	i = 0;
	while (i < tmp->precision)
	{
		putchar_and_count('0', tmp);
		i += 1;
	}
}
