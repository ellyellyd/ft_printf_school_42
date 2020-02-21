#include "libftprintf.h"

char	*get_s_and_mod_w_f(t_frm *tmp, va_list argptr)
{
	char			*s;
	int long long	l;

	l = ((tmp->size == 0) ? \
		 (va_arg(argptr, int)) : (va_arg(argptr, long long int)));
	if (tmp->size == 6 || tmp->size == 66)
		l = ((tmp->size == 66) ? ((char)l) : ((short)l));
	else if (tmp->size == 1 || tmp->size == 11 || tmp->size == 0)
		l = ((tmp->size == 11) ? ((long long int)l) : ((long int)l));
	if (l < 0)
	{
		tmp->sgn = '-';
		l *= -1;
		tmp->w -= 1;
	}
	else if (tmp->plus || tmp->space)
		tmp->w -= 1;
	s = ft_test_itoa_unsigned_base(l, 10, 'X');
	return (s);
}
