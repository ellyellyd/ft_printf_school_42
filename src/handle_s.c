/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/12 22:09:31 by slisandr         ###   ########.fr       */
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
	if (tmp->w > 0)
	{
		t = ft_strlen(s) + 1;
		if (t >= tmp->w)
			tmp->w = 0;
		if (tmp->w > t)
			tmp->w = tmp->w - t;
		handle_minus(tmp, " ", 0);
	}
	ft_putstr(s);
	handle_minus(tmp, " ", 1);
}
