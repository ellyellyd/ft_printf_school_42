#include "libftprintf.h"
#include <stdio.h>

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp);
void	ft_nb_to_char(int l);


int	size_l(int l)
{
	int	i;

	i = 0;
//	printf("%d\n", l); // check
	while (l % 10 != 0)
	{
//		write(1, "HI\n", 3); // check
		i++;
		l /= 10;
	}
	return (i);
}

t_frm	is_it_smth_else(const char *format, int	i) // bew func
{
	t_frm		tmp;
	char		c;
	int			l;

	l = 0;
	tmp.plus = 0;
	tmp.nb = 0;
	tmp.space = 0;
	tmp.zero = 0;
	c = format[i];
	while (!(c == 'd' || c == 'i' || c == 'o' || \
			c == 'u' || c == 'x' || c == 'X' || \
			c == 'c' || c == 's' || c == 'p' || format[i] == '\0'))
	{
	//	printf("here: %c\n", format[i]);// check
		if (c == '+')
			tmp.plus = 1;
		if (c == ' ')
			tmp.space = 1;
		if (c == '0')
			tmp.zero = 1;
		else if (c > '0' && c <= '9')
		{
			l = l + (c - 48);
			i++;
			if (format[i] >= '0' && format[i] <= '9')
					l = l * 1;
		}
		tmp.nb = l;
//		printf("here: %d\n", tmp.nb);// check
		i++;
		c = format[i];
	}
	return (tmp); 
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	argptr;
	t_frm	tmp; // for flags and etc

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
		//	printf("check: %c\n", format[i]);// check
			tmp = is_it_smth_else(format, i); // new for ecrier flags and etc
			while (format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && \
					format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && \
					format[i] != 'c' && format[i] != 's' && format[i] != 'p' && \
					format[i] != '\0')
				i++;
		//	printf("%c\n", format[i]);//check
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
	int	l;
	int	t;
	char	*s;

	l = 0;
	if (format[i] == 'i' || format[i] == 'd')
	{
		l = va_arg(argptr, int);
//		printf("%i\n", tmp.nb);// check
		if (tmp.plus == 1 && tmp.nb == 0 && l >= 0)
			write(1, "+", 1);
//		printf("%i\n", tmp.space);//check
		if (tmp.space == 1 && tmp.plus != 1 && tmp.nb < 1)
			write(1, " ", 1);
		if (tmp.nb > 0)
		{
			//LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK
			t = size_l(l);
		//	printf("%i %i %i\n", tmp.nb, t, tmp.space);// check
			if (t >= tmp.nb)
				tmp.nb = 0;
			if (tmp.nb > t)
			{
				tmp.nb = tmp.nb - t;
				if (tmp.plus == 1)
					tmp.nb = tmp.nb - 1;
			}
		//	printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
			while (tmp.nb > 0)
			{
				write(1, " ", 1);
				tmp.nb--;
			}
			if (tmp.plus == 1 && l >= 0)
				write(1, "+", 1);
		}
		ft_putnbr(l);
	}
	else if (format[i] == 'x')
	{
		l = va_arg(argptr, int);
		if (tmp.nb > 0)
		{
			t = size_l(l);
		//	printf("%i %i\n", t, tmp.nb);// check
			if (t >= tmp.nb)
				tmp.nb = 0;
			if (tmp.nb > t)
				tmp.nb = tmp.nb - t;
		//	printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
			while (tmp.nb > 0)
			{
				write(1, " ", 1);
				tmp.nb--;
			}
		}
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
		if (tmp.nb > 0)
		{
			t = size_l(l) - 1;
//			printf("%i\n", t);// check
			if (t >= tmp.nb)
				tmp.nb = 0;
			if (tmp.nb > t)
			{
				tmp.nb = tmp.nb - t;
				if (tmp.plus == 1)
					tmp.nb = tmp.nb - 1;
			}
//			printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
			while (tmp.nb > 0)
			{
				write(1, " ", 1);
				tmp.nb--;
			}
		}
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
		if (tmp.nb > 0)
		{
			t = size_l(l) - 1;
//			printf("%i\n", t);// check
			if (t >= tmp.nb)
				tmp.nb = 0;
			if (tmp.nb > t)
				tmp.nb = tmp.nb - t;
//			printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
			while (tmp.nb > 0)
			{
				write(1, " ", 1);
				tmp.nb--;
			}
		}
		if (l < 0)
		{
			s = ft_itoa_unsigned_base((unsigned int)l, 10, 'X');
			l = 0;
			while (s[l] != '\0')
				write(1, &s[l++], 1);
		}
		else
			ft_putnbr(l);
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
