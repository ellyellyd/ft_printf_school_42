/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:49:35 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 00:42:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_xx(t_frm *tmp, va_list argptr, char *c, char x)
{
	unsigned long long		l2;
	int						t;
	char					*s;

	l2 = va_arg(argptr, unsigned long long);
	if (tmp->size == 6)
		fix_s((s = ft_test_itoa_unsigned_base((short int)l2, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 12, 11);
	else if (tmp->size == 66)
		fix_s((s = ft_test_itoa_unsigned_base((signed char)l2, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 13, 13);
	else
		s = ft_test_itoa_unsigned_base(l2, 16, x);
	t = ft_strlen(s);
	if (tmp->w > 0)
	{
		tmp->w = ((t >= tmp->w) ? (0) : (tmp->w));
		tmp->w = ((tmp->w > t) ? (tmp->w - t) : (tmp->w));
		tmp->w = ((tmp->hash == 1 && s[0] != '0') ? (tmp->w - 2) : (tmp->w));
		handle_minus(tmp, c, 0);
	}
	if (tmp->hash == 1 && s[0] != '0')
		write(1, ((x == 'X') ? ("0X") : ("0x")), 2);
	ft_putstr(s);
	tmp->ret += ft_strlen(s);
	handle_minus(tmp, c, 1);
}
