/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:49:35 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/15 20:28:45 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hash_xx(t_frm *tmp, char *s, char x)
{
	if (tmp->hash == 1 && s[0] != '0')
	{
		write(1, ((x == 'X') ? ("0X") : ("0x")), 2);
		tmp->ret += 2;
	}
}

void	handle_xx(t_frm *tmp, va_list argptr, char *c, char x)
{
	unsigned long long		l2;
	int						t;
	char					*s;

	l2 = ((tmp->size == 0) ? (va_arg(argptr, int)) : (va_arg(argptr, unsigned long long)));
	if (tmp->size == 6)
		fix_s((s = ft_test_itoa_unsigned_base((short int)l2, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 12, 11);
	else if (tmp->size == 66)
		fix_s((s = ft_test_itoa_unsigned_base((signed char)l2, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 13, 13);
	else
		s = ft_test_itoa_unsigned_base(l2, 16, x);
	if (tmp->zero != 0)
		handle_hash_xx(tmp, s, x);
	t = ft_strlen(s);
	if (tmp->w > 0)
	{
		tmp->w = ((t >= tmp->w) ? (0) : (tmp->w));
		tmp->w = ((tmp->w > t) ? (tmp->w - t) : (tmp->w));
		tmp->w = ((tmp->hash == 1 && s[0] != '0') ? (tmp->w - 2) : (tmp->w));
	}
	tmp->ret += ft_strlen(s);
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
	if (tmp->zero == 0)
		handle_hash_xx(tmp, s, x);
	ft_putstr(s);
	ft_strdel(&s);
	/* if (tmp->minus == 0) */
	handle_minus(tmp, ((tmp->minus) ? (" ") : (c)), 1, "1");
	/* printf("   handle_xx: tmp->zero = %d   ", tmp->zero); */
}
