#include "libftprintf.h"

void	handle_c(t_frm *tmp, va_list argptr, int *l)
{
	(*l) = va_arg(argptr, int);
	tmp->width = tmp->width - 1;
	handle_minus(tmp, " ", 0);
	ft_putchar((char)(*l));
	handle_minus(tmp, " ", 1);
}
