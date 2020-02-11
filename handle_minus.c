#include "libftprintf.h"

void	handle_minus(t_frm *tmp, char *c, int cmp)
{
	if (tmp->minus == cmp)
	{
		while (tmp->width > 0)
		{
			write(1, c, 1);
			(tmp->width)--;
		}
	}
}
