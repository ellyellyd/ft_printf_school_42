#include "libftprintf.h"

void	check_flags_1_new(t_frm *tmp, int t, char *s)
{
	if ((tmp->plus == 1 && tmp->sgn != '-') && (\
			(tmp->minus == 1 && tmp->zero == 0) ||	\
			(((tmp->zero == 1 || tmp->minus == 1) && tmp->w != 0) == 0) || \
			(s[0] == '0' && tmp->zero == 0 && tmp->minus == 0)))
		putchar_and_count('+', tmp);
	if (tmp->space == 1 && tmp->plus == 0 && tmp->sgn != '-' && (tmp->w == 0 || t >= tmp->w))
	{
		tmp->space = 0;
		putchar_and_count(' ', tmp);
	}
	if ((tmp->space == 1 && tmp->sgn != '-') &&	\
		 ((s[0] == '0' && tmp->w != 0) || \
		  (tmp->minus == 1 && tmp->w != 0 && s[0] != '0') || \
		  (tmp->w != 0 && s[0] != '0' && tmp->zero == 1)))
	{
		putchar_and_count(' ', tmp);
		tmp->w = tmp->w - 1;
	}
}

void	handle_fwp(t_frm *tmp, char *s)
{
	int		t;
	int		i;
	int		was_minus_or_plus;

	t = ft_strlen(s);
	if (tmp->precision >= t)
		tmp->precision -= t;
	else
		tmp->precision = 0;
	was_minus_or_plus = 0;
	if ((was_minus_or_plus = (tmp->sgn == '-' && tmp->zero)))
		putchar_and_count('-', tmp);
	else if ((was_minus_or_plus = (tmp->plus && tmp->sgn != '-' && (tmp->precision <= 0 || tmp->minus))))
		putchar_and_count('+', tmp);
	if (tmp->w >= 0)
	{
		if (tmp->w <= tmp->precision + t)
			tmp->w = 0;
		else
		{
			tmp->w -= tmp->precision;
			tmp->w = ((tmp->sgn == '-' || tmp->plus == 1 || tmp->space != 0) ? (tmp->w - t - 1) : (tmp->w - t));
			i = 0;
			if (tmp->precision > 0 && tmp->zero && !(tmp->plus) && !(tmp->minus))
			{
				/* printf("***w = %d, pr = %d***", tmp->w, tmp->precision); */
				while (i < tmp->w)
				{
					putchar_and_count(' ', tmp);
					i += 1;
				}
			}
		} 
		handle_minus(tmp, ((tmp->zero) ? ("0") : (" ")), 0);
	}
	if (tmp->sgn == '-' && !was_minus_or_plus)
		putchar_and_count('-', tmp);
	if (/* !(tmp->plus) &&  */!was_minus_or_plus)
		check_flags_1_new(tmp, t, s);
	handle_precision(tmp, s);
	if (tmp->size == 6 || tmp->plus == 1 || \
		((s[0] != '0') || (s[0] == '0' && tmp->w > 0 && tmp->precision > 0)))
	{
		ft_putstr(s);
		tmp->ret += t;
	}
	if (tmp->minus && tmp->w > 0)
		handle_minus(tmp, " ", 1);
}

void	handle_size_id(t_frm *tmp, long long int *l)
{
	char	*s;

	if (tmp->size == 6 || tmp->size == 66)
		(*l) = ((tmp->size == 66) ? ((char)(*l)) : ((short)(*l)));
	else if (tmp->size == 1 || tmp->size == 11 || tmp->size == 0)
		(*l) = ((tmp->size == 11) ? ((long long int)(*l)) : ((long int)(*l)));
	if ((*l) < 0)
	{
		tmp->sgn = '-';
		(*l) *= -1;
	}
	s = ft_test_itoa_unsigned_base((*l), 10, 'X');
	handle_fwp(tmp, s);
}

void	handle_id_new(t_frm *tmp, va_list argptr)
{
	int long long	l;

	l = ((tmp->size == 0) ? (va_arg(argptr, int)) : (va_arg(argptr, long long int)));
	/* printf("   l = %lld   ", l); */
	handle_size_id(tmp, &l);
}
