#include "libftprintf.h"

#define STEPS_F 23
#define STEPS_D 52
#define STEPS_LD 80

char	*ft_ftoa(float value, t_frm *f)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(STEPS_F + 1);
	tmp = ft_itoa_unsigned_base((long long int)value, 10, 'X');
	ft_strncpy(str, tmp, (i = ft_strlen(tmp)));
	str[i++] = '.';
	f->w -= 1;
	while (i < STEPS_F)
	{
		value = 10 * (value - (float)((long long int) value));
		str[i] = (long long int)value + '0';
		i += 1;
	}
	ft_strdel(&tmp);
	return (str);
}

char	*ft_dtoa(double value, t_frm *f)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(STEPS_D + 1);
	tmp = ft_itoa_unsigned_base((long long int)value, 10, 'X');
	ft_strncpy(str, tmp, (i = ft_strlen(tmp)));
	str[i++] = '.';
	f->w -= 1;
	while (i < STEPS_D)
	{
		value = 10 * (value - (double)((long long int) value));
		str[i] = (long long int)value + '0';
		i += 1;
	}
	ft_strdel(&tmp);
	return (str);
}

char	*ft_ldtoa(long double value, t_frm *f)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(STEPS_LD + 1);
	tmp = ft_itoa_unsigned_base((long long int)value, 10, 'X');
	ft_strncpy(str, tmp, (i = ft_strlen(tmp)));
	str[i++] = '.';
	f->w -= 1;
	while (i < STEPS_LD)
	{
		value = 10 * (value - (long double)((long long int) value));
		str[i] = (long long int)value + '0';
		i += 1;
	}
	ft_strdel(&tmp);
	return (str);
}

char	*get_s_f(t_frm *tmp, va_list argptr)
{
	char			*s;
	long double		value_ld;
	double			value_d;
	float			value_f;

	s = NULL;
	if (tmp->size == 10)
	{
		value_ld = va_arg(argptr, long double);
		if (value_ld < 0)
		{
			tmp->sgn = '-';
			value_ld *= -1;
			tmp->w -= 1;
		}
		s = ft_ldtoa(value_ld, tmp);
	}
	else if (tmp->size == 1)
	{
		value_d = va_arg(argptr, double);
		if (value_d < 0)
		{
			tmp->sgn = '-';
			value_d *= -1;
			tmp->w -= 1;
		}
		s = ft_dtoa(value_d, tmp);
	}
	else if (tmp->size == 0)
	{
		value_f = (float)va_arg(argptr, double);
		if (value_f < 0)
		{
			tmp->sgn = '-';
			value_f *= -1;
			tmp->w -= 1;
		}
		s = ft_ftoa(value_f, tmp);
	}
	return (s);
}

void	handle_sgn_and_space_f(t_frm *tmp)
{
	if (tmp->sgn_is_printed == 0)
	{
		if (tmp->sgn == '-')
		{
			putchar_and_count('-', tmp);
			tmp->sgn_is_printed = 1;
		}
		else if (tmp->plus)
		{
			putchar_and_count('+', tmp);
			tmp->sgn_is_printed = 1;
		}
		else if (tmp->space)
		{
			putchar_and_count(' ', tmp);
			tmp->sgn_is_printed = 1;
		}
	}
}

void	handle_zero_f(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (!(tmp->minus))
	{
		if (tmp->zero && tmp->precision <= 0 && t + 1 < tmp->w + 1)
			handle_sgn_and_space_f(tmp);
		while (i < tmp->w - MAX_OF_TWO(tmp->precision, t))
		{
			putchar_and_count(\
				((tmp->zero && tmp->precision < 0) ? \
				 ('0') : (' ')), tmp);
			i += 1;
		}
		if (!(tmp->plus) && tmp->precision != 0)
			handle_sgn_and_space_f(tmp);
	}
}

void	print_string_f(t_frm *tmp, char *s, int t)
{
	int		i;
	int		j;

	handle_sgn_and_space_f(tmp);
	i = 0;
	while (s[i])
	{
		putchar_and_count(s[i], tmp);
		if (s[i] == '.')
		{
			i += 1;
			break ;
		}
		i += 1;
	}
	j = 0;
	while (s[i] && j < tmp->precision)
	{
		putchar_and_count(s[i], tmp);
		i += 1;
		j += 1;
	}
}

void	handle_minus_f(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (tmp->minus)
	{
		while (i < tmp->w - MAX_OF_TWO(tmp->precision, t))
		{
			putchar_and_count(' ', tmp);
			i += 1;
		}
	}
}

void	handle_f(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	if (tmp->precision < 0)
	{
		/* tmp->w = 8; */
		tmp->precision = 6;
	}
	s = get_s_f(tmp, argptr);
	t = ft_strlen(s);
	print_string_f(tmp, s, t);
	handle_minus_f(tmp, t);
	ft_strdel(&s);
}
