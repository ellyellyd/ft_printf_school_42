/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:46:20 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 05:37:37 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	record_flag(char c, char c_prev, t_frm *tmp)
{
	if (c == '+')
		tmp->plus = 1;
	if (c == ' ')
		tmp->space = 1;
	if (c == '0' && !ft_isdigit(c_prev))
		tmp->zero = 1;
	if (c == '-')
		tmp->minus = 1;
	if (c == '#')
		tmp->hash = 1;
}

void	record_size_and_width(char c, t_frm *tmp, char const *format, int *i)
{
	if (c == 'L')
		tmp->size = 10;
	else if (c == 'h')
	{
		if (format[(*i) + 1] == 'h')
		{
			tmp->size = 66;
			c = format[(*i)++];
		}
		else
			tmp->size = 6;
	}
	else if (c == 'l')
	{
		if (format[(*i) + 1] == 'l')
		{
			tmp->size = 11;
			c = format[(*i)++];
		}
		else
			tmp->size = 1;
	}
	else if (c >= '0' && c <= '9')
		tmp->w = tmp->w * 10 + (c - '0');
}

t_frm	process_flags(const char *format, int i)
{
	t_frm		tmp;
	char		c;
	char		c_prev;

	reset_struct(&tmp);
	tmp.ret = 0;
	c = format[i];
	c_prev = format[i - 1];
	while (!(c == 'd' || c == 'i' || c == 'o' || \
			 c == 'u' || c == 'x' || c == 'X' || \
			 c == 'c' || c == 's' || c == 'p' || c == '%' || format[i] == '\0'))
	{
		record_flag(c, c_prev, &tmp);
		record_size_and_width(c, &tmp, format, &i);
		(i)++;
		c_prev = c;
		c = format[i];
	}
	return (tmp);
}
