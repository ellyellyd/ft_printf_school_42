#include "libftprintf.h"
#include <stdio.h>

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp);
void	ft_nb_to_char(int l);

t_frm	is_it_smth_else(const char *format, int	i) // bew func
{
	t_frm		tmp;
	char		c;
	int			l;

	l = 0;
	tmp.plus = 0;
	tmp.nb = 0;
	tmp.space = 0;
	c = format[i];
	while ((c != 'd' || c != 'i' || c != 'o' || \
			c != 'u' || c != 'x' || c != 'X' || \
			c != 'c' || c != 's' || c != 'p') && format[i] != '\0')
	{
		if (c == '+')
			tmp.plus = 1;
		if (c == ' ')
			tmp.space = 1;
		if (c >= '1' && c <= '9')
		{
			l = l + (c - 48);
			i++;
			while (format[i++] == 0)
				l = l * 10;
			if (format[i] > '0' && format[i] <= '9')
				l = l * 10;
		}
		tmp.nb = l;
		c = format[i++];
	}
	return (tmp); 
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	argptr;
	t_frm	tmp; // for flags and ets

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
		{ // new
			tmp = is_it_smth_else(format, i); // new for ecrier flags and etc
			while (format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && \
					format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && \
					format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != '\0')
				i++;
			insert_format(format, i, argptr, tmp);
		} // new
		i++;
	}
	if (format[i] == '\0')
		return (i);
	va_end(argptr);
	return (-1);
}

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp)
{
	int				l;
	char			*s;

	l = 0;
	if (format[i] == 'i' || format[i] == 'd')
	{
		l = va_arg(argptr, int);
		if (tmp.plus == 1)
			if (l >= 0)
				write(1, "+", 1);
		if (tmp.space == 1 && tmp.plus != 1)
			write(1, " ", 1);
		ft_putnbr(l);
	}
	else if (format[i] == 'x')
	{
		l = va_arg(argptr, int);
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 16, 'x');
			l = 0;
		}
		else
			s = ft_itoa_base(l, 16);
		l = 0;
		while (s[l] != '\0')
			write(1, &s[l++], 1);
	}
	else if (format[i] == 'X')
	{
		l = va_arg(argptr, int);
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 16, 'X');
			l = 0;
		}
		else
			s = X_ft_itoa_base(l, 16);
		l = 0;
		while (s[l] != '\0')
			write(1, &s[l++], 1);
	}
	else if (format[i] == 'u')
	{
		l = va_arg(argptr, int);
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 10, 'X');
			l = 0;
			while (s[l] != '\0')
				write(1, &s[l++], 1);
		}
		else
		{
			l = va_arg(argptr, int);
			ft_putnbr(l);
		}
	}
	else if (format[i] == 'o')
	{
		l = va_arg(argptr, int);
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 8, 'X');
			l = 0;
			while (s[l] != '\0')
				write(1, &s[l++], 1);
		}
		else
			a10_in_8(l);
	}
	else if (format[i] == 'c')
	{
		l = va_arg(argptr, int);
		ft_nb_to_char(l);
	}
	else if (format[i] == 's')
	{
		s = va_arg(argptr, char*);
		ft_putstr(s);
	}	
	else if (format[i] == '%')
		ft_putchar('%');
}

void	ft_nb_to_char(int l)
{
	char	c;

	c = l;
	write(1, &c, 1);
}
