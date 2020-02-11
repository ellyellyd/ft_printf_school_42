#include "libftprintf.h"

void	handle_X(t_frm *tmp, va_list argptr, char *s, char *c)
{
	unsigned long long		l2;
	int						t;

	l2 = va_arg(argptr, unsigned long long);
	if (tmp->size == 6)
		fix_s((s = ft_test_itoa_unsigned_base((short int)l2, 16, 'X')), 'F', 12, 11);
	else if (tmp->size == 66)
		fix_s((s = ft_test_itoa_unsigned_base((signed char)l2, 16, 'X')), 'F', 13, 13);
	else
		s = ft_test_itoa_unsigned_base(l2, 16, 'X');
	t = 0;
	if (tmp->width > 0)
	{
		t = ft_strlen(s);
		tmp->width = ((t >= tmp->width) ? (0) : (tmp->width));
		tmp->width = ((tmp->width > t) ? (tmp->width - t) : (tmp->width));
		tmp->width = ((tmp->hash == 1 && s[0] != '0') ? (tmp->width - 2) : (tmp->width));
		handle_minus(tmp, c, 0);
	}
	if (tmp->hash == 1 && s[0] != '0')
		write(1, "0X", 2);
	ft_putstr(s);
	handle_minus(tmp, c, 1);
}
