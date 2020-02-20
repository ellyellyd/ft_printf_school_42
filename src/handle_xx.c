/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:49:35 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/19 07:30:42 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hash_xx(t_frm *tmp, char *s, char x)
{
	if (tmp->hash == 1 && s[0] != '0')
		putstr_and_count((x == 'X') ? ("0X") : ("0x"), tmp);
}

char	*get_s_xx(t_frm *tmp, char x, va_list argptr)
{
	char				*s;
	unsigned long long	value;

	s = NULL;
	value = ((tmp->size == 0) ? \
			 (va_arg(argptr, unsigned int)) : \
			 (va_arg(argptr, unsigned long long)));
	if (tmp->size == 6)
		fix_s((s = ft_test_itoa_unsigned_base((short int)value, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 12, 11);
	else if (tmp->size == 66)
		fix_s((s = ft_test_itoa_unsigned_base((signed char)value, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 13, 13);
	else
		s = ft_test_itoa_unsigned_base(value, 16, x);
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

void	handle_xx(t_frm *tmp, va_list argptr, char x, char c)
{
	int						t;
	char					*s;

	s = get_s_xx(tmp, x, argptr);
	t = ft_strlen(s);
	handle_hash_and_zero_xx(tmp, t, s, x);
	print_string(tmp, s, t, c);
	handle_minus_xx(tmp, t);
	ft_strdel(&s);
}
