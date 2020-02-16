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

void	handle_minus(t_frm *tmp, char *c, int is_minus)
{
	int		i;

	if (tmp->minus == is_minus)
	{
		i = 0;
		while (i < tmp->w && tmp->w - i > ((*c == '0') ? (tmp->precision) : (-1)))
		{
			write(1, c, 1);
			tmp->ret += 1;
			i += 1;
		}
	}
}
