/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:25:50 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/13 09:16:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	insert_format(const char *format, int i, va_list argptr, t_frm *tmp)
{
	int					l;
	char				c;

	l = 0;
	c = ((tmp->zero == 1) ? ('0') : (' '));
/*	if (format[i] == 'f')// NEW_NEW_NEW!!! DO IT!!!
	{
	f = va_arg(argptr, double);
	printf("%f\n", f); // check
	}
*/
	if (format[i] == 'i' || format[i] == 'd')
		handle_id(tmp, argptr, &c);
	else if (format[i] == 'x')
		handle_xx(tmp, argptr, &c, 'x');
	else if (format[i] == 'X')
		handle_xx(tmp, argptr, &c, 'X');
	else if (format[i] == 'u')
		handle_u(tmp, argptr, &c);
	else if (format[i] == 'o')
		handle_o(tmp, argptr, &c);
	else if (format[i] == 'p')
		handle_p(tmp, argptr);
	else if (format[i] == 'c')
		handle_c(tmp, argptr, &l);
	else if (format[i] == 's')
		handle_s(tmp, argptr);
}

int		is_garbage(char c)
{
	if ((c != 'd' && c != 'i' && c != 'o' &&	\
		 c != 'u' && c != 'x' && c != 'X' && \
		 c != 'c' && c != 's' && c != 'p') && \
		c != '\0')
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int			i;
	va_list		argptr;
	t_frm		tmp;
	size_t		ret;

	i = 0;
	tmp.ret = 0;
	ret = 0;
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			ret += 1;
			continue ;
		}
		else if (format[i + 1])
		{
			i += 1;
			if (format[i] == '%')
			{
				handle_percent(&tmp);
				ret += tmp.ret;
				continue ;
			}
			tmp = process_flags(format, i); // new for ecrier flags and etc
			while (is_garbage(format[i]))
				i++;
			insert_format(format, i, argptr, &tmp);
			ret += tmp.ret;
			tmp.ret = 0;
		}
		i++;
	}
	if (format[i] == '\0')
		return (ret);
	va_end(argptr);
	return (-1);
}
