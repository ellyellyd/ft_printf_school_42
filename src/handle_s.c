/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 04:08:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** CHECKS:
**
** printf("%i %i\n", t, tmp->w);
** printf("%i %i %i\n", tmp->w, t, tmp->minus);
*/

void	handle_s(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	t = 0;
	s = va_arg(argptr, char*);
	/* printf("handle_s: tmp->w = %d\n", tmp->w); */
	if (tmp->w > 0)
	{
		t = ft_strlen(s) + 1;
		if (t >= tmp->w)
			tmp->w = 0;
		else
			tmp->w = tmp->w - t;
		handle_minus(tmp, " ", 0);
		while (tmp->w >= 0)
		{
			ft_putchar(' ');
			tmp->ret += 1;
			(tmp->w)--;
		}
	}
	ft_putstr(s);
	tmp->ret += ft_strlen(s);
	handle_minus(tmp, " ", 1);
}
