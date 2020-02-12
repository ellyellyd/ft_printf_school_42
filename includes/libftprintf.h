/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:02:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 00:58:01 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"

/*
** stdio must be removed before defence!
*/

# include <stdio.h>

/*
** nb - how many spaces or zeroes, hash - #,
** w (width) - between 1 and 9, precision - .#,
** size: ll = 11, l = 1, hh = 66, h = 6, L = 10, else == 0.
*/

typedef	struct		s_form
{
	char	sgn;

	char	format;
	char	*string;

	int		nb;

	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;

	int		w;
	int		precision;
	int		size;

	size_t	ret;
}					t_frm;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				a10_in_8(int l);
void				x_10_in_16(int l);
char				*ft_itoa_base(int value, int base);
char				*x_ft_itoa_base(int value, int base);
char				*ft_itoa_unsigned_base(unsigned int value, \
												int base, char c);
void				handle_minus(t_frm *tmp, char *c, int cmp);
void				fix_s(char *s, char c, int cmp, int n);
void				handle_c(t_frm *tmp, va_list argptr, int *l);
void				handle_s(t_frm *tmp, va_list argptr);
void				handle_p(t_frm *tmp, va_list argptr);
void				handle_o(t_frm *tmp, va_list argptr, char *c);
void				handle_u(t_frm *tmp, va_list argptr, char *c);
void				handle_xx(t_frm *tmp, va_list argptr, char *c, char x);
void				handle_id(t_frm *tmp, va_list argptr, char *c);

/*
** check
*/

char				*ft_test_itoa_unsigned_base(unsigned long long value, \
												int base, char c);

#endif
