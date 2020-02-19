/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:00:35 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/19 05:49:28 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_string(t_frm *tmp, char *s, int w, int t)
{
	int		i;

	i = 0;
	if ((tmp->w > 0 || tmp->precision != 0 || s[0] != '0') && \
		((s[0] == '0' && (tmp->w == 0 || tmp->precision > 0)) || \
		 (s[0] == '0' && tmp->hash == 1 && tmp->zero == 1) || \
		 (s[0] != '0' && tmp->precision < 0) || \
		 (s[0] != '0' && tmp->hash && tmp->precision > 0) || \
		 (s[0] != '0' && !(tmp->hash) && tmp->precision > 0)))
	{
		while (i++ < tmp->precision - t)
			putchar_and_count('0', tmp);
		putstr_and_count(s, tmp);
	}
	else if (w > 0 && tmp->precision >= 0)
		putchar_and_count(' ', tmp);
}
