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
	if (tmp->minus == is_minus)
	{
		while (tmp->w > 0 && tmp->w > tmp->precision)
		{
			write(1, c, 1);
			tmp->ret += 1;
			(tmp->w)--;
		}
	}
}
