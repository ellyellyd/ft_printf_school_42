/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:52:47 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/12 21:52:59 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_c(t_frm *tmp, va_list argptr, int *l)
{
	(*l) = va_arg(argptr, int);
	tmp->width = tmp->width - 1;
	handle_minus(tmp, " ", 0);
	ft_putchar((char)(*l));
	handle_minus(tmp, " ", 1);
}
