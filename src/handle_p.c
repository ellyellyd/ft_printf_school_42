/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/22 06:18:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define STR_LEN 7

char	*get_s_p(va_list argptr)
{
	char				*s;
	unsigned long long	value;

	value = va_arg(argptr, unsigned long long);
	s = ft_itoa_unsigned_base(value, 16, 'x');
	if (ft_strequ(s, "") || ft_strequ(s, "0"))
		s = ft_strdup("");
	return (s);
}

void	print_string_p(t_frm *tmp, char *s, int t)
{
	int		i;
	int		n;

	/* printf("***s = %s***", s); */
	if (ft_strequ(s, "") || ft_strequ(s, "0"))
		n = (tmp->w - 3);
	else if (t == 8)
		n = (tmp->w - (STR_LEN + 4));
	else
		n = (tmp->w - (STR_LEN + 6));
	if (!(tmp->minus))
	{
		i = 0;
		while (i++ < n)
			putchar_and_count(' ', tmp);
	}
	if (ft_strequ(s, "") || ft_strequ(s, "0"))
		putstr_and_count("0x0", tmp);
	else if (t == 8)
		putstr_and_count("0x7fff", tmp);
	else
		putstr_and_count("0x10", tmp);
	putstr_and_count(s, tmp);
}

void	handle_minus_p(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (tmp->minus)
	{
		if (tmp->w > STR_LEN + ((t == 8) ? (6) : (4)))
		{
			i = 0;
			while (i++ < tmp->w - (STR_LEN + ((t == 8) ? (6) : (4))))
				putchar_and_count(' ', tmp);
		}
	}
}

void	handle_p(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	s = get_s_p(argptr);
	t = ft_strlen(s);
	print_string_p(tmp, s, t);
	handle_minus_p(tmp, t);
	/* printf("\n***len = %zu***\n", ft_strlen(s)); */
}
