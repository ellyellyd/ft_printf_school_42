/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/19 08:21:34 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_o(t_frm *tmp, va_list argptr)
{
	char	*s;
	unsigned long long	value;

	if (tmp->size == 6)
		value = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		value = (unsigned char)va_arg(argptr, unsigned long long);
	else
		value = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(value, 8, 'X');
	return (s);
}

void	mod_width_o(t_frm *tmp, char *s, int t)
{
	if (tmp->w > 0)
	{
		if (tmp->hash == 1 && s[0] != '0' && !(t + 1 <= tmp->precision))
			tmp->w -= 1

			;
	}
}

// A - space, X - '0'

void	handle_zero_o(t_frm *tmp, int t)
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

void	handle_hash_o(t_frm *tmp, char *s, int t)
{
	if (tmp->hash == 1 && s[0] != '0' && t + 1 > tmp->precision)
		putchar_and_count('0', tmp);
}

void	handle_hash_and_zero_o(t_frm *tmp, int t, char *s)
{
	if (tmp->hash && tmp->zero)
	{
		if (t + 1 < tmp->w - 1 && tmp->precision > 0)
		{
			mod_width_o(tmp, s, t);
			handle_zero_o(tmp, t);
			handle_hash_o(tmp, s, t);
		}
		else
		{
			mod_width_o(tmp, s, t);
			handle_hash_o(tmp, s, t);
			handle_zero_o(tmp, t);
		}
	}
	else
	{
		mod_width_o(tmp, s, t);
		handle_zero_o(tmp, t);
		handle_hash_o(tmp, s, t);
	}
}

void	handle_minus_o(t_frm *tmp, int t)
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

void	handle_o(t_frm *tmp, va_list argptr, char c)
{
	char	*s;
	int		t;

	s = get_s_o(tmp, argptr);
	t = ft_strlen(s);
	handle_hash_and_zero_o(tmp, t, s);
	print_string(tmp, s, t, c);
	handle_minus_o(tmp, t);
	ft_strdel(&s);
}
