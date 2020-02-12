/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/12 22:15:49 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_p(va_list argptr)
{
	int		l;
	char	*s;

	l = 0;
	l = va_arg(argptr, unsigned long long);
	s = ft_itoa_unsigned_base(l, 16, 'x');
	write(1, "0x10", 4);
	ft_putstr(s);
}
