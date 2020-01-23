#include "libftprintf.h"
#include <stdio.h>

void	insert_format(const char *format, int i, va_list argptr);
void	ft_nb_to_char(int l);

int		ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	argptr;

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
			insert_format(format, i, argptr);
		i++;
	}
	if (format[i] == '\0')
		return (i);
	va_end(argptr);
	return (-1);
}

void	insert_format(const char *format, int i, va_list argptr)
{
	int				l;
	char			*s;

	l = 0;
	if (format[i] == 'i' || format[i] == 'd')
	{
		l = va_arg(argptr, int);
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
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 9, 'X');
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
