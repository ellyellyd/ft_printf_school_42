#include "libftprintf.h"

void	handle_o(t_frm *tmp, va_list argptr, char *c)
{
	char				*s;
	unsigned long long	l2;
	int					t;

	t = 0;
	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else
		l2 = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 8, 'X');
	l2 = 0;
	if (tmp->width > 0)
	{
		t = ft_strlen(s);
		tmp->width = ((t >= tmp->width) ? (0) : (tmp->width));
		tmp->width = ((tmp->width > t) ? (tmp->width - t) : (tmp->width));
		tmp->width = ((tmp->hash == 1 && s[0] != '0') ? (tmp->width - 1) : (tmp->width));
		handle_minus(tmp, c, 0);
	}
	if (tmp->hash == 1 && s[0] != '0')
		write(1, "0", 1);
	ft_putstr(s);
	handle_minus(tmp, c, 1);
}
