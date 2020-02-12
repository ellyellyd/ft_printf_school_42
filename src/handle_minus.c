/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:28 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 00:29:43 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_minus(t_frm *tmp, char *c, int cmp)
{
	if (tmp->minus == cmp)
	{
		while (tmp->w > 0)
		{
			write(1, c, 1);
			tmp->ret += 1;
			(tmp->w)--;
		}
	}
}
