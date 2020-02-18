/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:28 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/16 04:35:47 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_minus(t_frm *tmp, char *c, int is_minus, char *s)
{
	int		i;

	if (tmp->minus == is_minus && \
		(tmp->plus || \
		 s[0] != '0' || \
		 (s[0] == '0' && tmp->w > 0 && tmp->precision > 0)))
	{
		i = 0;
		while (i < tmp->w && tmp->w - i > ((*c == '0') ? (tmp->precision) : (0)))
		{
			putchar_and_count(*c, tmp);
			i += 1;
		}
	}
}
