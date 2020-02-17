#include "libftprintf.h"

void	handle_precision(t_frm *tmp, char *s)
{
	int		i;

	if ((s[0] != '0') || (s[0] == '0' && tmp->w > 0 && tmp->precision > 0))
	{
		i = 0;
		while (i < tmp->precision)
		{
			putchar_and_count('0', tmp);
			i += 1;
		}
	}
}
