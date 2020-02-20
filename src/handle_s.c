/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 04:08:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_s(va_list argptr)
{
	char	*s;

	s = va_arg(argptr, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	return (s);
}

void	handle_s(t_frm *tmp, va_list argptr)
{
	char	*s;
	char	*s_tmp;
	int		t;

	s_tmp = NULL;
	t = 0;
	s = get_s_s(argptr);
	if (s != NULL && tmp->w >= tmp->precision && s[0] == '\0' && tmp->precision > 0 && tmp->w > 0)
		handle_minus(tmp, " ", 1, "1");
	if (tmp->precision > 0)
	{
		if (tmp->w <= tmp->precision)
			s[tmp->precision] = '\0';
		else if (tmp->minus)
		{
			ft_memset((void *)s + tmp->precision, ' ', tmp->w - tmp->precision);
			s[tmp->w] = '\0';
		}
		else
		{
			s_tmp = ft_strdup(s);
			ft_memset((void *)s, ' ', tmp->w);
			s[tmp->w] = '\0';
			ft_strncpy(s + (tmp->w - tmp->precision) - 1, s_tmp, tmp->precision);
			s[tmp->w - 1] = '\0';
		}
	}
	if (tmp->w > 0)
	{
		t = ((tmp->minus) ? (ft_strlen(s)) : (ft_strlen(s) + 1));
		if (t >= tmp->w)
			tmp->w = 0;
		else
			tmp->w = tmp->w - t;
		while (tmp->w >= 0 && tmp->minus == 0)
		{
			putchar_and_count(' ', tmp);
			(tmp->w)--;
		}
	}
	ft_putstr(s);
	tmp->ret += ft_strlen(s);
	if (tmp->precision <= 0)
		handle_minus(tmp, " ", 1, "1");
}
