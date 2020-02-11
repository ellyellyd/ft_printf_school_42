#include "libftprintf.h"

void	handle_u(t_frm *tmp, va_list argptr, char *c)
{
	unsigned long long		l2;
	char					*s;
	int						t;

	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else
		l2 = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 10, 'X');
	t = ft_strlen(s);
	if (tmp->width > 0)
	{
		tmp->width = ((t >= tmp->width) ? (0) : (tmp->width));
		if (tmp->width > t)
		{
			tmp->width = tmp->width - t;
			tmp->width = ((tmp->plus == 1) ? (tmp->width - 1) : (tmp->width));
		}
		handle_minus(tmp, c, 0);
		ft_putstr(s);
	}
	else
		ft_putstr(s);
}
