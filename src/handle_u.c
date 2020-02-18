/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 00:51:35 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_u(t_frm *tmp, va_list argptr, char *c)
{
	unsigned long long		l2;
	char					*s;
	int						t;

	if (tmp->size == 6)
		l2 = (unsigned short)va_arg(argptr, unsigned long long);
	if (tmp->size == 66)
		l2 = (unsigned char)va_arg(argptr, unsigned long long);
	else if (tmp->size == 11 || tmp->size == 1)
		l2 = va_arg(argptr, unsigned long long);
	else
		l2 = (unsigned int)va_arg(argptr, unsigned long long);
	s = ft_test_itoa_unsigned_base(l2, 10, 'X');
	t = ft_strlen(s);
	if (tmp->w > 0)
	{
		tmp->w = ((t >= tmp->w) ? (0) : (tmp->w));
		if (tmp->w > t)
		{
			tmp->w = tmp->w - t;
			tmp->w = ((tmp->plus == 1) ? (tmp->w - 1) : (tmp->w));
		}
		handle_minus(tmp, c, 0, "1");
		ft_putstr(s);
	}
	else
		ft_putstr(s);
	tmp->ret += ft_strlen(s);
}
