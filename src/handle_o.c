/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/19 07:28:50 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
void	handle_hash_o(t_frm *tmp, char *s)
{
	if (tmp->hash == 1 && s[0] != '0')
		putchar_and_count('0', tmp);
}

char	*get_s_o(t_frm *tmp, char x)
{
	char	*s;
	unsigned long long	l2;

	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else
		l2 = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 8, 'X');
	return (s);
}

void	mod_width_xx(t_frm *tmp, char *s)
{
	if (tmp->w > 0)
	{
		if (tmp->hash == 1 && s[0] != '0')
			tmp->w -= 2;
	}
}

void	handle_zero_xx(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (tmp->minus == 0)
	{
		while (i < tmp->w - MAX_OF_TWO(tmp->precision, t))
		{
			putchar_and_count(((tmp->zero && tmp->precision < 0) ? \
							   ('0') : (' ')), tmp);
			i += 1;
		}
	}
}

void	handle_minus_xx(t_frm *tmp, int t)
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

void	handle_hash_and_zero_xx(t_frm *tmp, int t, char *s, char x)
{
	if (tmp->hash && tmp->zero)
	{
		if (t + 2 < tmp->w - 1 && tmp->precision > 0)
		{
			mod_width_xx(tmp, s);
			handle_zero_xx(tmp, t);
			handle_hash_xx(tmp, s, x);
		}
		else
		{
			mod_width_xx(tmp, s);
			handle_hash_xx(tmp, s, x);
			handle_zero_xx(tmp, t);
		}
	}
	else
	{
		if (tmp->hash)
			mod_width_xx(tmp, s);
		handle_zero_xx(tmp, t);
		handle_hash_xx(tmp, s, x);
	}
}

void	handle_xx(t_frm *tmp, va_list argptr, char x)
{
	unsigned long long		value;
	int						t;
	char					*s;

	value = ((tmp->size == 0) ? \
		  (va_arg(argptr, unsigned int)) : \
		  (va_arg(argptr, unsigned long long)));
	s = get_s_xx(tmp, value, x);
	t = ft_strlen(s);
	handle_hash_and_zero_xx(tmp, t, s, x);
	print_string(tmp, s, t);
	handle_minus_xx(tmp, t);
	ft_strdel(&s);
}
*/














//////////////////////////////////////////////////

void	handle_o(t_frm *tmp, va_list argptr, char *c)
{
	char				*s;
	unsigned long long	l2;
	int					w;
	int					t;
	int					i;

	w = tmp->w;
	t = 0;
	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else
		l2 = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 8, 'X');
	l2 = 0;
	t = ft_strlen(s);
	if (tmp->w > 0)
	{
		tmp->w = ((t >= tmp->w) ? (0) : (tmp->w));
		tmp->w = ((t < tmp->w) ? (tmp->w - t) : (tmp->w));
		tmp->w = ((tmp->hash == 1 && s[0] != '0') ? (tmp->w - 1) : (tmp->w));
	}
	if (tmp->zero == 0 && tmp->minus == 0)
	{
		while (tmp->w > 0)
		{
			putchar_and_count(' ', tmp);
			tmp->w -= 1;
		}
	}
	else if (tmp->zero == 1 && tmp->w > 0 && tmp->minus != 1)
	{
		while (tmp->w > 0)
		{
			putchar_and_count('0', tmp);
			tmp->w -= 1;
		}
	}
	/* if (tmp->w > 0 && tmp->minus == 0) */
	/* 	handle_minus(tmp, ((tmp->zero == 1) ? ("0") : (" ")), 0, "1"); */
	if (tmp->hash == 1 && s[0] != '0')
	{
		write(1, "0", 1);
		tmp->ret += 1;
	}
	i = 0;
	if (\
		(tmp->w > 0 || tmp->precision != 0 || s[0] != '0') && \
		((s[0] == '0' && tmp->w > 0 && tmp->precision > 0) || \
		 (s[0] == '0' && (tmp->w <= 0 || tmp->precision > 0)) ||	\
		 (s[0] != '0' && tmp->precision < 0) || \
		 (s[0] != '0' && !(tmp->hash) && tmp->precision > 0))\
		)
	{
		while (i++ < tmp->precision - t)
			putchar_and_count('0', tmp);
		putstr_and_count(s, tmp);
	}
	else if (w > 0 || tmp->hash)
		putchar_and_count(((tmp->hash) ? ('0') : (' ')), tmp);
	if ((s[0] == '0') && (tmp->precision <= 0) && (tmp->w > 0))
		putchar_and_count(' ', tmp);
	if (w > t + tmp->precision + ((tmp->plus || tmp->hash) ? (1) : (0)))
	{
		tmp->w = ((tmp->precision >= 0) ? (tmp->w - 1) : (tmp->w));
		handle_minus(tmp, ((tmp->minus) ? (" ") : (c)), 1, "1");
	}
	ft_strdel(&s);
}
