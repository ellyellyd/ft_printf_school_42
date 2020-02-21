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

void	print_string_s(t_frm *tmp, char *s, int t)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	if (s[0] != '0' || tmp->precision >= 0)
	{
		if (tmp->w != 0)
		{
			if (!(tmp->minus))
			{
				j = ((t < tmp->precision || tmp->precision < 0) ? \
					 (tmp->w - t) : (tmp->w - tmp->precision));
				while (j-- > 0)
					putchar_and_count(' ', tmp);
			}
			n = ((tmp->precision > 0) ? (tmp->precision) : (t));
			while (i < n && s[i])
				putchar_and_count(s[i++], tmp);
		}
		else if (tmp->w == 0)
		{
			if (tmp->precision > 0)
			{
				while (i < tmp->precision && s[i])
					putchar_and_count(s[i++], tmp);
			}
			else if (tmp->precision < 0)
				putstr_and_count(s, tmp);
		}
	}
	else if (tmp->w != 0 && tmp->precision >= 0)
		putchar_and_count(' ', tmp);
}

void	handle_minus_s(t_frm *tmp, int t)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tmp->minus)
	{
		if (tmp->w > 0)
		{
			j = ((t < tmp->precision || tmp->precision < 0) ? \
				 (tmp->w - t) : (tmp->w - tmp->precision));
			while (i++ < j)
				putchar_and_count(' ', tmp);
		}
	}
}

void	handle_s(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	s = get_s_s(argptr);
	t = ft_strlen(s);
	if (tmp->precision != 0)
		print_string_s(tmp, s, t);
	handle_minus_s(tmp, t);
	/* ft_strdel(&s); */
}
