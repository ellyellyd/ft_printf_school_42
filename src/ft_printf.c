/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:25:50 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/12 21:49:56 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp);

int	size_s(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


void	clean_struct(t_frm *tmp)
{
	tmp->size = 0;
	tmp->plus = 0;
	tmp->signe = '\0';
	tmp->string = NULL;
	tmp->minus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->width = 0;
	tmp->hash = 0;
	tmp->format = 0;
}

void	record_flag(char c, t_frm *tmp)
{
	if (c == '+')
		tmp->plus = 1;
	if (c == ' ')
		tmp->space = 1;
	if (c == '0')
		tmp->zero = 1;
	if (c == '-')
		tmp->minus = 1;
	if (c == '#')
		tmp->hash = 1;
}

void	record_size_and_width(char c, t_frm *tmp, char const *format, int *i)
{
	int			l;

	l = 0;
	if (c == 'L')
		tmp->size = 10;
	if (c == 'h')
	{
		if (format[(*i) + 1] == 'h')
		{
			tmp->size = 66;
			c = format[(*i)++];
		}
		else
			tmp->size = 6;
	}
	if (c == 'l')
	{
		if (format[(*i) + 1] == 'l')
		{
			tmp->size = 11;
			c = format[(*i)++];
		}
		else
			tmp->size = 1;
	}
	else if (c > '0' && c <= '9')
	{
		l = l + (c - 48);
		tmp->width = l;
	}
}

t_frm	is_it_smth_else(const char *format, int i) // bew func
{
	t_frm		tmp;
	char		c;

	clean_struct(&tmp);
	c = format[i];
	while (!(c == 'd' || c == 'i' || c == 'o' || \
			c == 'u' || c == 'x' || c == 'X' || \
			c == 'c' || c == 's' || c == 'p' || format[i] == '\0'))
	{
//	printf("here: %c\n", format[i]);// check
		record_flag(c, &tmp);
		record_size_and_width(c, &tmp, format, &i);
//		printf("here: %d\n", tmp.width);// check
		i++;
		c = format[i];
	}
	return (tmp);
}

int		check_type(char c)
{
	if (c != 'd' && c != 'i' && c != 'o' && \
		c != 'u' && c != 'x' && c != 'X' && \
		c != 'c' && c != 's' && c != 'p')
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int			i;
	int			res;
	va_list		argptr;
	t_frm		tmp;

	i = 0;
	res = 0;
	va_start(argptr, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\n' && format[i])
			write(1, &format[i++], 1);
		if (format[i] == '\n')
			write(1, "\n", 1);
		else if (format[i++] == '%')
		{
//	printf("check: %c\n", format[i]);// check
			tmp = is_it_smth_else(format, i); // new for ecrier flags and etc
			while (check_type(format[i]) && format[i] != '\0')
				i++;
//	printf("%c\n", format[i]);//check
			insert_format(format, i, argptr, tmp);
		}
		i++;
	}
	if (format[i] == '\0')
		return (i);
	va_end(argptr);
	return (-1);
}

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp)
{
	int					l;
	char				c;

	l = 0;
	c = ((tmp.zero == 1) ? ('0') : (' '));
/*	if (format[i] == 'f')// NEW_NEW_NEW!!! DO IT!!!
	{
		f = va_arg(argptr, double);
		printf("%f\n", f); // check
	}
*/
	if (format[i] == 'i' || format[i] == 'd')
		handle_id(&tmp, argptr, &c);
	else if (format[i] == 'x')
		handle_xx(&tmp, argptr, &c, 'x');
	else if (format[i] == 'X')
		handle_xx(&tmp, argptr, &c, 'X');
	else if (format[i] == 'u')
		handle_u(&tmp, argptr, &c);
	else if (format[i] == 'o')
		handle_o(&tmp, argptr, &c);
	else if (format[i] == 'p')
		handle_p(argptr);
	else if (format[i] == 'c')
		handle_c(&tmp, argptr, &l);
	else if (format[i] == 's')
		handle_s(&tmp, argptr);
	else if (format[i] == '%')
		ft_putchar('%');
}
