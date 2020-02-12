/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 00:53:57 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_o(t_frm *tmp, va_list argptr, char *c)
{
	char				*s;
	unsigned long long	l2;
	int					t;

	t = 0;
	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else
		l2 = va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 8, 'X');
	l2 = 0;
	if (tmp->w > 0)
	{
		t = ft_strlen(s);
		tmp->w = ((t >= tmp->w) ? (0) : (tmp->w));
		tmp->w = ((tmp->w > t) ? (tmp->w - t) : (tmp->w));
		tmp->w = ((tmp->hash == 1 && s[0] != '0') ? (tmp->w - 1) : (tmp->w));
		handle_minus(tmp, c, 0);
	}
	if (tmp->hash == 1 && s[0] != '0')
	{
		write(1, "0", 1);
		tmp->ret += 1;
	}
	ft_putstr(s);
	tmp->ret += ft_strlen(s);
	handle_minus(tmp, c, 1);
}
