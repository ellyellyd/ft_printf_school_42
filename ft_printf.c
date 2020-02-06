/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:25:50 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/06 13:26:17 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	insert_format(const char *format, int i, va_list argptr, t_frm tmp);
void	ft_nb_to_char(int l);

int	size_s(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	size_l(int l)
{
	int			i;

	i = 1;
//	printf("%d\n", l);//  check
	while (l / 10 != 0)
	{
//		write(1, "HI\n", 3);//  check
		i++;
		l /= 10;
	}
	return (i);
}

t_frm	is_it_smth_else(const char *format, int i) // bew func
{
	t_frm		tmp;
	char		c;
	int			l;

	l = 0;
	tmp.size = 0;
	tmp.plus = 0;
	tmp.signe = '\0';
	tmp.string = NULL;
	tmp.minus = 0;
	tmp.space = 0;
	tmp.zero = 0;
	tmp.width = 0;
	tmp.hash = 0;
	tmp.format = 0;
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
		if (c == '-')
			tmp.minus = 1;
		if (c == '#')
			tmp.hash = 1;
		if (c == 'L')
			tmp.size = 10;
		if (c == 'h')
		{
			if (format[i + 1] == 'h')
			{
				tmp.size = 66;
				c = format[i++];
			}
			else
				tmp.size = 6;
		}
		if (c == 'l')
		{
			if (format[i + 1] == 'l')
			{
				tmp.size = 11;
				c = format[i++];
			}
			else
				tmp.size = 1;
		}
		else if (c > '0' && c <= '9')
		{
			l = l + (c - 48);
			tmp.width = l;
		}
//		printf("here: %d\n", tmp.width);// check
		i++;
		c = format[i];
	}
	return (tmp);
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
			while (format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && \
					format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && \
					format[i] != 'c' && format[i] != 's' && format[i] != 'p' && \
					format[i] != '\0')
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
	unsigned long long	l2;
	long long int		l3;
	int					t;
	int					ul;
	char				*s;
	char				c;
	int					flag;
//	double				f;

	flag = 0;
	c = ' ';
	ul = 0;
	l = 0;
	s = NULL;
	l3 = 0;
	l2 = 0;
	if (tmp.zero == 1)
		c = '0';
/*	if (format[i] == 'f')// NEW_NEW_NEW!!! DO IT!!!
	{
		f = va_arg(argptr, double);
		printf("%f\n", f); // check
	}
*/
	if (format[i] == 'i' || format[i] == 'd')
	{
		if (/*tmp.size == 1 || tmp.size == 11 || */tmp.size == 6 || tmp.size == 66)
		{
	//		write(1, "hi\n", 3);//check
			l3 = va_arg(argptr, long long int);
		  //printf("%d\n", tmp.size);//printf("%d\n", (char)l3);//check// why here l3 becomes = ' '??
			if (tmp.size == 66)
			{
				//printf("HI\n");//check// why here l3 becomes = ' '??
				if ((char)l3 < 0)
				{
					tmp.signe = '-';
					l3  *= -1;
				}
				//???????????????????      tmp.string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
				s = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
        //printf("%s\n", s);//check
				if (tmp.plus == 1 && tmp.minus == 1 && tmp.zero == 0 && tmp.signe == '\0')
				{
					flag = 1;
					write(1, "+", 1);
				}
				if ((tmp.plus == 1 || tmp.width != 0) && tmp.minus == 1 && tmp.zero == 0 && tmp.signe == '-')
				{
					flag = 1;
					write(1, "-", 1);
				}
				if (tmp.plus == 1 && (tmp.zero == 1 || tmp.minus == 1) && tmp.width != 0 && tmp.signe != '-' && flag == 0)
					write(1, "+", 1);
	//		printf("%i\n", tmp.space);//check
				t = size_s(s);
//			printf("%d\n", l);
				if (tmp.space == 1 && tmp.plus == 0 && tmp.width == 0 && tmp.minus == 0 && tmp.signe != '-')
				{
					tmp.space = 0;
					write(1, " ", 1);
				}
				if (tmp.space == 1 && tmp.plus == 0 && (tmp.width == 0 || t >=  tmp.width) && tmp.minus == 0 && tmp.signe != '-')
				{
					tmp.space = 0;
					write(1, " ", 1);
				}
				if (tmp.space == 1 && s[0] == '0' && tmp.width != 0 && tmp.signe != '-')
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
			//if (tmp.space == 1 && tmp.minus == 0 && tmp.width != 0 && l > 0 && tmp.zero != 0)
			//{
			//	write(1, " ", 1);
			//	tmp.width = tmp.width - 1;
			//}
				if (tmp.space == 1 && tmp.minus == 1 && tmp.width != 0 && s[0] != '0' && tmp.signe != '-')
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
				if (tmp.space == 1 && tmp.width != 0 && s[0] != '0' && tmp.signe != '-' && tmp.zero == 1)
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
				if (tmp.width == 0 && (tmp.minus == 1 || tmp.zero == 1) && s[0] != '0' && tmp.signe != '-' && flag == 0)
					write(1, "-", 1);
				if (tmp.width >= 0)
				{
		//		printf("%i %i %i\n", tmp.width, t, tmp.space);// check
					if (t >= tmp.width)
						tmp.width = 0;
					if (tmp.width > t)
					{
						tmp.width = tmp.width - t;
						if (tmp.plus == 1 || (s[0] != '0' && tmp.signe != '-'))
							tmp.width = tmp.width - 1;
					}
	//		printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
					if (tmp.zero == 1 && s[0] != '0' && tmp.signe != '-' && tmp.minus == 0)
						write(1, "-", 1);
					if (tmp.minus == 0)
					{
						while (tmp.width > 0)
						{
							write(1, &c, 1);
							tmp.width--;
						}
					}
					if (tmp.plus == 1 && s[0] == '0' && tmp.signe != '-' && tmp.zero == 0 && tmp.minus == 0)
						write(1, "+", 1);
					else if (tmp.zero == 0 && tmp.minus == 0 && s[0] != '0' && tmp.signe == '-')
						write(1, "-", 1);
				}
				ft_putstr(s);
				if (tmp.minus == 1)
				{
					while (tmp.width > 0)
					{
						write(1, &c, 1);
						tmp.width--;
					}
				}
      }
			if (tmp.size == 6)
			{
				//printf("i");//check// why here l3 becomes = ' '??
				if ((short)l3 < 0)
				{
					tmp.signe = '-';
					l3  *= -1;
				}
				//???????????????????      tmp.string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
				s = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
				if (tmp.plus == 1 && tmp.minus == 1 && tmp.zero == 0 && tmp.signe == '\0')
				{
					flag = 1;
					write(1, "+", 1);
				}
				if ((tmp.plus == 1 || tmp.width != 0) && tmp.minus == 1 && tmp.zero == 0 && tmp.signe == '-')
				{
					flag = 1;
					write(1, "-", 1);
				}
				if (tmp.plus == 1 && (tmp.zero == 1 || tmp.minus == 1) && tmp.width != 0 && tmp.signe != '-' && flag == 0)
					write(1, "+", 1);
	//		printf("%i\n", tmp.space);//check
				t = size_s(s);
//			printf("%d\n", l);
				if (tmp.space == 1 && tmp.plus == 0 && tmp.width == 0 && tmp.minus == 0 && tmp.signe != '-')
				{
					tmp.space = 0;
					write(1, " ", 1);
				}
				if (tmp.space == 1 && tmp.plus == 0 && (tmp.width == 0 || t >=  tmp.width) && tmp.minus == 0 && tmp.signe != '-')
				{
					tmp.space = 0;
					write(1, " ", 1);
				}
				if (tmp.space == 1 && s[0] == '0' && tmp.width != 0 && tmp.signe != '-')
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
			//if (tmp.space == 1 && tmp.minus == 0 && tmp.width != 0 && l > 0 && tmp.zero != 0)
			//{
			//	write(1, " ", 1);
			//	tmp.width = tmp.width - 1;
			//}
				if (tmp.space == 1 && tmp.minus == 1 && tmp.width != 0 && s[0] != '0' && tmp.signe != '-')
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
				if (tmp.space == 1 && tmp.width != 0 && s[0] != '0' && tmp.signe != '-' && tmp.zero == 1)
				{
					write(1, " ", 1);
					tmp.width = tmp.width - 1;
				}
				if (tmp.width == 0 && (tmp.minus == 1 || tmp.zero == 1) && s[0] != '0' && tmp.signe != '-' && flag == 0)
					write(1, "-", 1);
				if (tmp.width >= 0)
				{
		//		printf("%i %i %i\n", tmp.width, t, tmp.space);// check
					if (t >= tmp.width)
						tmp.width = 0;
					if (tmp.width > t)
					{
						tmp.width = tmp.width - t;
						if (tmp.plus == 1 || (s[0] != '0' && tmp.signe != '-'))
							tmp.width = tmp.width - 1;
					}
	//		printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
					if (tmp.zero == 1 && s[0] != '0' && tmp.signe != '-' && tmp.minus == 0)
						write(1, "-", 1);
					if (tmp.minus == 0)
					{
						while (tmp.width > 0)
						{
							write(1, &c, 1);
							tmp.width--;
						}
					}
					if (tmp.plus == 1 && s[0] == '0' && tmp.signe != '-' && tmp.zero == 0 && tmp.minus == 0)
						write(1, "+", 1);
					else if (tmp.zero == 0 && tmp.minus == 0 && s[0] != '0' && tmp.signe == '-')
						write(1, "-", 1);
				}
				ft_putstr(s);
				if (tmp.minus == 1)
				{
					while (tmp.width > 0)
					{
						write(1, &c, 1);
						tmp.width--;
					}
				}
			}
		}
/*			else if (tmp.size == 66)
			{
				if ((char)l3 < 0)
				{
					tmp.signe = '-';
					l2  *= -1;
				}
				tmp.string = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
			}
			else if (tmp.size == 1)
			{
				if ((long int)l3 < 0)
				{
					tmp.signe = '-';
					l2  *= -1;
				}
				tmp.string = ft_test_itoa_unsigned_base((long int)l3, 10, 'X');
			}
		}*/
		else
		{
			l = va_arg(argptr, long long int);
	//	printf("%i\n", l);// check
			if (tmp.plus == 1 && tmp.minus == 1 && tmp.zero == 0 && l >= 0)
			{
				flag = 1;
				write(1, "+", 1);
			}
			if ((tmp.plus == 1 || tmp.width != 0) && tmp.minus == 1 && tmp.zero == 0 && l < 0)
			{
				flag = 1;
				write(1, "-", 1);
			}
			if (tmp.plus == 1 && (tmp.zero == 1 || tmp.minus == 1) && tmp.width != 0 && l >= 0 && flag == 0)
				write(1, "+", 1);
	//		printf("%i\n", tmp.space);//check
			t = size_l(l);
//			printf("%d\n", l);
			if (tmp.space == 1 && tmp.plus == 0 && tmp.width == 0 && tmp.minus == 0 && l >= 0)
			{
				tmp.space = 0;
				write(1, " ", 1);
			}
			if (tmp.space == 1 && tmp.plus == 0 && (tmp.width == 0 || t >=  tmp.width) && tmp.minus == 0 && l >= 0)
			{
				tmp.space = 0;
				write(1, " ", 1);
			}
			if (tmp.space == 1 && l == 0 && tmp.width != 0)
			{
				write(1, " ", 1);
				tmp.width = tmp.width - 1;
			}
			//if (tmp.space == 1 && tmp.minus == 0 && tmp.width != 0 && l > 0 && tmp.zero != 0)
			//{
			//	write(1, " ", 1);
			//	tmp.width = tmp.width - 1;
			//}
			if (tmp.space == 1 && tmp.minus == 1 && tmp.width != 0 && l != 0 && l > 0)
			{
				write(1, " ", 1);
				tmp.width = tmp.width - 1;
			}
			if (tmp.space == 1 && tmp.width != 0 && l > 0 && tmp.zero == 1)
			{
				write(1, " ", 1);
				tmp.width = tmp.width - 1;
			}
			if (tmp.width == 0 && (tmp.minus == 1 || tmp.zero == 1) && l < 0 && flag == 0)
				write(1, "-", 1);
			if (l < 0)
				ul = l * -1;
			else
				ul = l;
			if (tmp.width >= 0)
			{
				t = size_l(ul);
	//		printf("%i %i %i\n", tmp.width, t, tmp.space);// check
				if (t >= tmp.width)
					tmp.width = 0;
				if (tmp.width > t)
				{
					tmp.width = tmp.width - t;
					if (tmp.plus == 1 || l < 0)
						tmp.width = tmp.width - 1;
				}
	//		printf("%i %i %i\n", tmp.nb, t, tmp.plus);// check
				if (tmp.zero == 1 && l < 0 && tmp.minus == 0)
					write(1, "-", 1);
				if (tmp.minus == 0)
				{
					while (tmp.width > 0)
					{
						write(1, &c, 1);
						tmp.width--;
					}
				}
				if (tmp.plus == 1 && l >= 0 && tmp.zero == 0 && tmp.minus == 0)
					write(1, "+", 1);
				else if (tmp.zero == 0 && tmp.minus == 0 && l < 0)
					write(1, "-", 1);
				if (l < 0)
					l = l * -1;
			}
			ft_putnbr(l);
			if (tmp.minus == 1)
			{
				while (tmp.width > 0)
				{
					write(1, &c, 1);
					tmp.width--;
				}
			}
		}
	}
	else if (format[i] == 'x')
	{
		l2 = va_arg(argptr, unsigned long long);
		if (tmp.size == 6)
		{
			s = ft_test_itoa_unsigned_base((short int)l2, 16, 'x');
			while (s[l] == 'f')
				l++;
			if (l > 12)
			{
				l = 11;
				while (l >= 0)
					s[l--] = ' ';
				l = 0;
				while(s[12 + l] != '\0')
				{
				   s[l] = s[12 + l];
				   l++;
				}
				s[l] = '\0';
				l = 0;
			}
		}
		else if (tmp.size == 66)
		{
			s = ft_test_itoa_unsigned_base((signed char)l2, 16, 'x');
			while (s[l] == 'f')
				l++;
			if (l > 13)
			{
				l = 13;
				while (l >= 0)
					s[l--] = ' ';
				l = 0;
				while(s[14 + l] != '\0')
				{
				   s[l] = s[14 + l];
				   l++;
				}
				s[l] = '\0';
				l = 0;
			}
		}
		else
			s = ft_test_itoa_unsigned_base(l2, 16, 'x');
		//printf("%s\n", s);//check
		l2 = 0;
		if (tmp.width > 0)
		{
			t = size_s(s);
//		printf("%i %i\n", t, tmp.width);// check
			if (t >= tmp.width)
				tmp.width = 0;
			if (tmp.width > t)
				tmp.width = tmp.width - t;
			if (tmp.hash == 1 && s[0] != '0')
				tmp.width = tmp.width - 2;
//		printf("%i %i %i\n", tmp.width, t, tmp.plus);// check
			if (tmp.minus == 0)
			{
				while (tmp.width > 0)
				{
					write(1, &c, 1);
					tmp.width--;
				}
			}
		}
		if (tmp.hash == 1 && s[0] != '0')
			write(1, "0x", 2);
		while (s[l] != '\0')
			write(1, &s[l++], 1);
		if (tmp.minus == 1)
		{
			while (tmp.width > 0)
			{
				write(1, &c, 1);
				tmp.width--;
			}
		}
	}
	else if (format[i] == 'X')
	{
		l2 = va_arg(argptr,unsigned long long);
		if (tmp.size == 6)
		{
			s = ft_test_itoa_unsigned_base((short int)l2, 16, 'X');
			while (s[l] == 'F')
				l++;
			if (l > 12)
			{
				l = 11;
				while (l >= 0)
					s[l--] = ' ';
				l = 0;
				while(s[12 + l] != '\0')
				{
				   s[l] = s[12 + l];
				   l++;
				}
				s[l] = '\0';
				l = 0;
			}
		}
		else if (tmp.size == 66)
		{
			s = ft_test_itoa_unsigned_base((signed char)l2, 16, 'X');
			while (s[l] == 'F')
				l++;
			if (l > 13)
			{
				l = 13;
				while (l >= 0)
					s[l--] = ' ';
				l = 0;
				while(s[14 + l] != '\0')
				{
				   s[l] = s[14 + l];
				   l++;
				}
				s[l] = '\0';
				l = 0;
			}
		}
		else
			s = ft_test_itoa_unsigned_base(l2, 16, 'X');
		//printf("%s\n", s);//check
		l2 = 0;
		if (tmp.width > 0)
		{
			t = size_s(s);
//		printf("%i %i\n", t, tmp.width);// check
			if (t >= tmp.width)
				tmp.width = 0;
			if (tmp.width > t)
				tmp.width = tmp.width - t;
			if (tmp.hash == 1 && s[0] != '0')
				tmp.width = tmp.width - 2;
//		printf("%i %i %i\n", tmp.width, t, tmp.plus);// check
			if (tmp.minus == 0)
			{
				while (tmp.width > 0)
				{
					write(1, &c, 1);
					tmp.width--;
				}
			}
		}
		if (tmp.hash == 1 && s[0] != '0')
			write(1, "0X", 2);
		while (s[l] != '\0')
			write(1, &s[l++], 1);
		if (tmp.minus == 1)
		{
			while (tmp.width > 0)
			{
				write(1, &c, 1);
				tmp.width--;
			}
		}
	}
	else if (format[i] == 'u')
	{
		if (tmp.size == 6)
			l2 = (unsigned short)va_arg(argptr, unsigned long long);
		if (tmp.size == 66)
			l2 = (unsigned char)va_arg(argptr, unsigned long long);
		else
			l2 = va_arg(argptr, unsigned long long);
		s = ft_test_itoa_unsigned_base(l2, 10, 'X');
	//	printf("%s\n", s);//check
		l2 = 0;
		if (tmp.width > 0)
		{
			t = size_s(s);
	//      printf("%i %i %i\n", tmp.width, t, tmp.space);// check
			if (t >= tmp.width)
				tmp.width = 0;
			if (tmp.width > t)
			{
				tmp.width = tmp.width - t;
				if (tmp.plus == 1)
					tmp.width = tmp.width - 1;
			}
			//  printf("%i %i %i\n", tmp.width, t, tmp.plus);// check
			if (tmp.minus == 0)
			{
				while (tmp.width > 0)
				{
					write(1, &c, 1);
					tmp.width--;
				}
			}
			while(s[l2] != '\0')
				write(1, &s[l2++], 1);

		}
		else
			while(s[l2] != '\0')
				write(1, &s[l2++], 1);
	}
	else if (format[i] == 'o')
	{
		if (tmp.size == 6)
			l2 = (unsigned short)va_arg(argptr, unsigned long long);
		else if (tmp.size == 66)
			l2 = (unsigned char)va_arg(argptr, unsigned long long);
		else
			l2 = va_arg(argptr, unsigned long long);
		//l2 = va_arg(argptr, unsigned long long);
		s = ft_test_itoa_unsigned_base(l2, 8, 'X');
		l2 = 0;
		if (tmp.width > 0)
		{
			t = size_s(s);
//		printf("%i %i\n", t, tmp.width);// check
			if (t >= tmp.width)
				tmp.width = 0;
			if (tmp.width > t)
				tmp.width = tmp.width - t;
			if (tmp.hash == 1 && s[0] != '0')
				tmp.width = tmp.width - 1;
//		printf("%i %i %i\n", tmp.width, t, tmp.plus);// check
			if (tmp.minus == 0)
			{
				while (tmp.width > 0)
				{
					write(1, &c, 1);
					tmp.width--;
				}
			}
		}
		if (tmp.hash == 1 && s[0] != '0')
			write(1, "0", 1);
		while (s[l] != '\0')
			write(1, &s[l++], 1);
		if (tmp.minus == 1)
		{
			while (tmp.width > 0)
			{
				write(1, &c, 1);
				tmp.width--;
			}
		}
	}
	else if (format[i] == 'p')
	{
		l = va_arg(argptr, unsigned long long);
		s = ft_itoa_unsigned_base(l, 16, 'x');
		write(1, "0x10", 4);
		l = 0;
		while (s[l] != '\0')
			write(1, &s[l++], 1);
	}
	else if (format[i] == 'c')
	{
		l = va_arg(argptr, int);
		tmp.width = tmp.width - 1;
		if (tmp.minus == 0)
		{
			while (tmp.width > 0)
			{
				write(1, " ", 1);
				tmp.width--;
			}
		}
		ft_nb_to_char(l);
		if (tmp.minus == 1)
		{
			while (tmp.width > 0)
			{
				write(1, " ", 1);
				tmp.width--;
			}
		}
	}
	else if (format[i] == 's')
	{
		s = va_arg(argptr, char*);
		if (tmp.width > 0)
		{
			t = size_s(s);
//		printf("%i %i\n", t, tmp.width);// check
			if (t >= tmp.width)
				tmp.width = 0;
			if (tmp.width > t)
				tmp.width = tmp.width - t;
//		printf("%i %i %i\n", tmp.width, t, tmp.minus);// check
			if (tmp.minus == 0)
			{
				while (tmp.width > 0)
				{
					write(1, " ", 1);
					tmp.width--;
				}
			}
		}
		ft_putstr(s);
		if (tmp.minus == 1)
		{
			while (tmp.width > 0)
			{
				write(1, " ", 1);
				tmp.width--;
			}
		}
	}
	else if (format[i] == '%')
		ft_putchar('%');
}

void	ft_nb_to_char(int l)
{
	char		c;

	c = l;
	write(1, &c, 1);
}
