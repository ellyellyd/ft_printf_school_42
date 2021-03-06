/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:31:28 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 07:43:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double	get_delta(t_frm *tmp)
{
	int		i;
	double	delta;

	i = 0;
	delta = 5;
	while (i < tmp->precision + 1)
	{
		delta /= 10;
		i += 1;
	}
	return (delta);
}

char	*get_s_f(t_frm *tmp, va_list argptr)
{
	char			*s;
	long double		value_ld;
	double			value_d;

	s = NULL;
	if (tmp->size == 10)
	{
		value_ld = va_arg(argptr, long double);
		value_ld = ((value_ld < 0) ? (value_ld * (-1)) : (value_ld));
		tmp->sgn = ((value_ld < 0) ? ('-') : (tmp->sgn));
		s = ft_ldtoa(value_ld + get_delta(tmp));
	}
	else if (tmp->size == 1 || tmp->size == 0)
	{
		value_d = va_arg(argptr, double);
		value_d = ((value_d < 0) ? (value_d * (-1)) : (value_d));
		tmp->sgn = ((value_d < 0) ? ('-') : (tmp->sgn));
		s = ft_dtoa(value_d + get_delta(tmp));
	}
	return (s);
}
