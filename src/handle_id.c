/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:17:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 01:21:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	putchar_and_count(char c, t_frm *tmp)
{
	write(1, &c, 1);
	tmp->ret += 1;
}

/*
** CHECKS:
**
** printf("%d\n", l);
** putchar_and_count(1, "HI\n", 3);
*/

int	size_l(int l)
{
	int			i;

	i = 1;
	while (l / 10 != 0)
	{
		i++;
		l /= 10;
	}
	return (i);
}

void	check_flags_1(t_frm *tmp, int *flag, int t)
{
	if (tmp->plus == 1 && tmp->minus == 1 && tmp->zero == 0 && tmp->sgn == '\0')
	{
		(*flag) = 1;
		putchar_and_count('+', tmp);
	}
	if ((tmp->plus == 1 || tmp->w != 0) && tmp->minus == 1 && tmp->zero == 0 && tmp->sgn == '-')
	{
		(*flag) = 1;
		putchar_and_count('-', tmp);
	}
	if (tmp->plus == 1 && (tmp->zero == 1 || tmp->minus == 1) && tmp->w != 0 && tmp->sgn != '-' && (*flag) == 0)
		putchar_and_count('+', tmp);
	if (tmp->space == 1 && tmp->plus == 0 && tmp->w == 0 && tmp->minus == 0 && tmp->sgn != '-')
	{
		tmp->space = 0;
		putchar_and_count(' ', tmp);
	}
	if (tmp->space == 1 && tmp->plus == 0 && (tmp->w == 0 || t >=  tmp->w) && tmp->minus == 0 && tmp->sgn != '-')
	{
		tmp->space = 0;
		putchar_and_count(' ', tmp);
	}
}

/*
** CHECK:
**
**
*/

void	handle_hh_and_h_in_di(t_frm *tmp, char *c, char *s, int *flag)
{
	int		t;

	t = 0;
	t = ft_strlen(s) + 1;
	check_flags_1(tmp, flag, t);
	if (tmp->space == 1 && s[0] == '0' && tmp->w != 0 && tmp->sgn != '-')
	{
		putchar_and_count(' ', tmp);
		tmp->w = tmp->w - 1;
	}
	//if (tmp->space == 1 && tmp->minus == 0 && tmp->w != 0 && l > 0 && tmp->zero != 0)
	//{
	//	putchar_and_count(' ', tmp);
	//	tmp->w = tmp->w - 1;
	//}
	if (tmp->space == 1 && tmp->minus == 1 && tmp->w != 0 && s[0] != '0' && tmp->sgn != '-')
	{
		putchar_and_count(' ', tmp);
		tmp->w = tmp->w - 1;
	}
	if (tmp->space == 1 && tmp->w != 0 && s[0] != '0' && tmp->sgn != '-' && tmp->zero == 1)
	{
		putchar_and_count(' ', tmp);
		tmp->w = tmp->w - 1;
	}
	if (tmp->w == 0 && (tmp->minus == 1 || tmp->zero == 1) && s[0] != '0' && tmp->sgn != '-' && (*flag) == 0)
		putchar_and_count('-', tmp);
	if (tmp->w >= 0)
	{
		//		printf("%i %i %i\n", tmp->w, t, tmp->space);// check
		if (t >= tmp->w)
			tmp->w = 0;
		if (tmp->w > t)
		{
			tmp->w = tmp->w - t;
			if (tmp->plus == 1 || (s[0] != '0' && tmp->sgn != '-'))
				tmp->w = tmp->w - 1;
		}
		//		printf("%i %i %i\n", tmp->nb, t, tmp->plus);// check
		if (tmp->zero == 1 && s[0] != '0' && tmp->sgn != '-' && tmp->minus == 0)
			putchar_and_count('-', tmp);
		handle_minus(tmp, c, 0);
		if (tmp->plus == 1 && s[0] == '0' && tmp->sgn != '-' && tmp->zero == 0 && tmp->minus == 0)
			putchar_and_count('+', tmp);
		else if (tmp->zero == 0 && tmp->minus == 0 && s[0] != '0' && tmp->sgn == '-')
			putchar_and_count('-', tmp);
	}
	ft_putstr(s);
	tmp->ret += ft_strlen(s);
	handle_minus(tmp, c, 1);
}

void	handle_id(t_frm *tmp, va_list argptr, char *c)
{
	int					l;
	unsigned long long	l2;
	long long int		l3;
	int					t;
	int					ul;
	char				*s;
	int					flag;

	flag = 0;
	ul = 0;
	l = 0;
	s = NULL;
	l3 = 0;
	l2 = 0;
	t = 0;
	if (tmp->size == 1 || tmp->size == 11 || tmp->size == 6 || tmp->size == 66)
	{
		//		putchar_and_count(1, "hi\n", 3);//check
		l3 = va_arg(argptr, long long int);
		//printf("%d\n", tmp->size);//printf("%d\n", (char)l3);//check// why here l3 becomes = ' '??
		if (tmp->size == 66)
		{
			//printf("HI\n");//check// why here l3 becomes = ' '??
			if ((char)l3 < 0)
			{
				tmp->sgn = '-';
				l3  *= -1;
			}
			//???????????????????      tmp->string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			s = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
			handle_hh_and_h_in_di(tmp, c, s, &flag);
		}
		if (tmp->size == 6)
		{
			//printf("i");//check// why here l3 becomes = ' '??
			if ((short)l3 < 0)
			{
				tmp->sgn = '-';
				l3  *= -1;
			}
			//???????????????????      tmp->string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			s = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			handle_hh_and_h_in_di(tmp, c, s, &flag);
		}
	}
/*			else if (tmp->size == 66)
			{
			if ((char)l3 < 0)
			{
			tmp->sgn = '-';
			l2  *= -1;
			}
			tmp->string = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
			}
			else if (tmp->size == 1)
			{
			if ((long int)l3 < 0)
			{
			tmp->sgn = '-';
			l2  *= -1;
			}
			tmp->string = ft_test_itoa_unsigned_base((long int)l3, 10, 'X');
			}
			}*/
	else
	{
		l = va_arg(argptr, long long int);
		//	printf("%i\n", l);// check
		if (tmp->plus == 1 && tmp->minus == 1 && tmp->zero == 0 && l >= 0)
		{
			flag = 1;
			putchar_and_count('+', tmp);
		}
		if ((tmp->plus == 1 || tmp->w != 0) && tmp->minus == 1 && tmp->zero == 0 && l < 0)
		{
			flag = 1;
			putchar_and_count('-', tmp);
		}
		if (tmp->plus == 1 && (tmp->zero == 1 || tmp->minus == 1) && tmp->w != 0 && l >= 0 && flag == 0)
			putchar_and_count('+', tmp);
		//		printf("%i\n", tmp->space);//check
		t = size_l(l);
//			printf("%d\n", l);
		if (tmp->space == 1 && tmp->plus == 0 && tmp->w == 0 && tmp->minus == 0 && l >= 0)
		{
			tmp->space = 0;
			putchar_and_count(' ', tmp);
		}
		if (tmp->space == 1 && tmp->plus == 0 && (tmp->w == 0 || t >=  tmp->w) && tmp->minus == 0 && l >= 0)
		{
			tmp->space = 0;
			putchar_and_count(' ', tmp);
		}
		if (tmp->space == 1 && l == 0 && tmp->w != 0)
		{
			putchar_and_count(' ', tmp);
			tmp->w = tmp->w - 1;
		}
		//if (tmp->space == 1 && tmp->minus == 0 && tmp->w != 0 && l > 0 && tmp->zero != 0)
		//{
		//	putchar_and_count(' ', tmp);
		//	tmp->w = tmp->w - 1;
		//}
		if (tmp->space == 1 && tmp->minus == 1 && tmp->w != 0 && l != 0 && l > 0)
		{
			putchar_and_count(' ', tmp);
			tmp->w = tmp->w - 1;
		}
		if (tmp->space == 1 && tmp->w != 0 && l > 0 && tmp->zero == 1)
		{
			putchar_and_count(' ', tmp);
			tmp->w = tmp->w - 1;
		}
		if (tmp->w == 0 && (tmp->minus == 1 || tmp->zero == 1) && l < 0 && flag == 0)
			putchar_and_count('-', tmp);
		if (l < 0)
			ul = l * -1;
		else
			ul = l;
		if (tmp->w >= 0)
		{
			t = size_l(ul);
			//		printf("%i %i %i\n", tmp->w, t, tmp->space);// check
			if (t >= tmp->w)
				tmp->w = 0;
			if (tmp->w > t)
			{
				tmp->w = tmp->w - t;
				if (tmp->plus == 1 || l < 0)
					tmp->w = tmp->w - 1;
			}
			//		printf("%i %i %i\n", tmp->nb, t, tmp->plus);// check
			if (tmp->zero == 1 && l < 0 && tmp->minus == 0)
				putchar_and_count('-', tmp);
			handle_minus(tmp, c, 0);
			if (tmp->plus == 1 && l >= 0 && tmp->zero == 0 && tmp->minus == 0)
				putchar_and_count('+', tmp);
			else if (tmp->zero == 0 && tmp->minus == 0 && l < 0)
				putchar_and_count('-', tmp);
			if (l < 0)
				l = l * -1;
		}
		ft_putnbr(l);
		tmp->ret += ft_strlen(ft_itoa(l));
		handle_minus(tmp, c, 1);
	}
}
