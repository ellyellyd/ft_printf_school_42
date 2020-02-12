#include "libftprintf.h"

void	handle_s(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	t = 0;
	s = va_arg(argptr, char*);
	if (tmp->width > 0)
	{
		t = ft_strlen(s) + 1;
//		printf("%i %i\n", t, tmp->width);// check
		if (t >= tmp->width)
			tmp->width = 0;
		if (tmp->width > t)
			tmp->width = tmp->width - t;
//		printf("%i %i %i\n", tmp->width, t, tmp->minus);// check
		handle_minus(tmp, " ", 0);
	}
	ft_putstr(s);
	handle_minus(tmp, " ", 1);
}
