/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/18 21:27:24 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
