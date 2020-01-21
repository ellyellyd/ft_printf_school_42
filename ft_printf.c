#include "libftprintf.h"

void	insert_format(const char *format, int i, va_list str);
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
		if (format[i++] == '%')
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
	int		l;
	char	*s;

	l = 0;
	if (format[i] == 'i' || format[i] == 'd' ||\
			format[i] == 'x' || format[i] == 'X')
	{
		l = va_arg(argptr, int);
		ft_putnbr(l);
	}
	else if (format[i] == 'u')
	{
		l = va_arg(argptr, int);
		if (l < 0)
			ft_putnbr(4294967296 + l);//it does not work
		//else
	}
	else if (format[i] == 'o')
	{
		l = va_arg(argptr, int);
		if (l < 0)
			ft_putnbr(37777777777 + l + 1);//it does not work
		//else
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
