#include "libftprintf->h"

void	handle_id(t_frm *tmp, va_list argptr)
{
	if (tmp->size == 1 || tmp->size == 11 || tmp->size == 6 || tmp->size == 66)
	{
		//		write(1, "hi\n", 3);//check
		l3 = va_arg(argptr, long long int);
		//printf("%d\n", tmp->size);//printf("%d\n", (char)l3);//check// why here l3 becomes = ' '??
		if (tmp->size == 66)
		{
			//printf("HI\n");//check// why here l3 becomes = ' '??
			if ((char)l3 < 0)
			{
				tmp->signe = '-';
				l3  *= -1;
			}
			//???????????????????      tmp->string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			s = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
			//printf("%s\n", s);//check
			if (tmp->plus == 1 && tmp->minus == 1 && tmp->zero == 0 && tmp->signe == '\0')
			{
				flag = 1;
				write(1, "+", 1);
			}
			if ((tmp->plus == 1 || tmp->width != 0) && tmp->minus == 1 && tmp->zero == 0 && tmp->signe == '-')
			{
				flag = 1;
				write(1, "-", 1);
			}
			if (tmp->plus == 1 && (tmp->zero == 1 || tmp->minus == 1) && tmp->width != 0 && tmp->signe != '-' && flag == 0)
				write(1, "+", 1);
			//		printf("%i\n", tmp->space);//check
			t = size_s(s);
//			printf("%d\n", l);
			if (tmp->space == 1 && tmp->plus == 0 && tmp->width == 0 && tmp->minus == 0 && tmp->signe != '-')
			{
				tmp->space = 0;
				write(1, " ", 1);
			}
			if (tmp->space == 1 && tmp->plus == 0 && (tmp->width == 0 || t >=  tmp->width) && tmp->minus == 0 && tmp->signe != '-')
			{
				tmp->space = 0;
				write(1, " ", 1);
			}
			if (tmp->space == 1 && s[0] == '0' && tmp->width != 0 && tmp->signe != '-')
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			//if (tmp->space == 1 && tmp->minus == 0 && tmp->width != 0 && l > 0 && tmp->zero != 0)
			//{
			//	write(1, " ", 1);
			//	tmp->width = tmp->width - 1;
			//}
			if (tmp->space == 1 && tmp->minus == 1 && tmp->width != 0 && s[0] != '0' && tmp->signe != '-')
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			if (tmp->space == 1 && tmp->width != 0 && s[0] != '0' && tmp->signe != '-' && tmp->zero == 1)
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			if (tmp->width == 0 && (tmp->minus == 1 || tmp->zero == 1) && s[0] != '0' && tmp->signe != '-' && flag == 0)
				write(1, "-", 1);
			if (tmp->width >= 0)
			{
				//		printf("%i %i %i\n", tmp->width, t, tmp->space);// check
				if (t >= tmp->width)
					tmp->width = 0;
				if (tmp->width > t)
				{
					tmp->width = tmp->width - t;
					if (tmp->plus == 1 || (s[0] != '0' && tmp->signe != '-'))
						tmp->width = tmp->width - 1;
				}
				//		printf("%i %i %i\n", tmp->nb, t, tmp->plus);// check
				if (tmp->zero == 1 && s[0] != '0' && tmp->signe != '-' && tmp->minus == 0)
					write(1, "-", 1);
				handle_minus(&tmp, &c, 0);
				if (tmp->plus == 1 && s[0] == '0' && tmp->signe != '-' && tmp->zero == 0 && tmp->minus == 0)
					write(1, "+", 1);
				else if (tmp->zero == 0 && tmp->minus == 0 && s[0] != '0' && tmp->signe == '-')
					write(1, "-", 1);
			}
			ft_putstr(s);
			handle_minus(&tmp, &c, 1);
		}
		if (tmp->size == 6)
		{
			//printf("i");//check// why here l3 becomes = ' '??
			if ((short)l3 < 0)
			{
				tmp->signe = '-';
				l3  *= -1;
			}
			//???????????????????      tmp->string = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			s = ft_test_itoa_unsigned_base((short)l3, 10, 'X');
			if (tmp->plus == 1 && tmp->minus == 1 && tmp->zero == 0 && tmp->signe == '\0')
			{
				flag = 1;
				write(1, "+", 1);
			}
			if ((tmp->plus == 1 || tmp->width != 0) && tmp->minus == 1 && tmp->zero == 0 && tmp->signe == '-')
			{
				flag = 1;
				write(1, "-", 1);
			}
			if (tmp->plus == 1 && (tmp->zero == 1 || tmp->minus == 1) && tmp->width != 0 && tmp->signe != '-' && flag == 0)
				write(1, "+", 1);
			//		printf("%i\n", tmp->space);//check
			t = size_s(s);
//			printf("%d\n", l);
			if (tmp->space == 1 && tmp->plus == 0 && tmp->width == 0 && tmp->minus == 0 && tmp->signe != '-')
			{
				tmp->space = 0;
				write(1, " ", 1);
			}
			if (tmp->space == 1 && tmp->plus == 0 && (tmp->width == 0 || t >=  tmp->width) && tmp->minus == 0 && tmp->signe != '-')
			{
				tmp->space = 0;
				write(1, " ", 1);
			}
			if (tmp->space == 1 && s[0] == '0' && tmp->width != 0 && tmp->signe != '-')
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			//if (tmp->space == 1 && tmp->minus == 0 && tmp->width != 0 && l > 0 && tmp->zero != 0)
			//{
			//	write(1, " ", 1);
			//	tmp->width = tmp->width - 1;
			//}
			if (tmp->space == 1 && tmp->minus == 1 && tmp->width != 0 && s[0] != '0' && tmp->signe != '-')
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			if (tmp->space == 1 && tmp->width != 0 && s[0] != '0' && tmp->signe != '-' && tmp->zero == 1)
			{
				write(1, " ", 1);
				tmp->width = tmp->width - 1;
			}
			if (tmp->width == 0 && (tmp->minus == 1 || tmp->zero == 1) && s[0] != '0' && tmp->signe != '-' && flag == 0)
				write(1, "-", 1);
			if (tmp->width >= 0)
			{
				//		printf("%i %i %i\n", tmp->width, t, tmp->space);// check
				if (t >= tmp->width)
					tmp->width = 0;
				if (tmp->width > t)
				{
					tmp->width = tmp->width - t;
					if (tmp->plus == 1 || (s[0] != '0' && tmp->signe != '-'))
						tmp->width = tmp->width - 1;
				}
				//		printf("%i %i %i\n", tmp->nb, t, tmp->plus);// check
				if (tmp->zero == 1 && s[0] != '0' && tmp->signe != '-' && tmp->minus == 0)
					write(1, "-", 1);
				handle_minus(&tmp, &c, 0);
				if (tmp->plus == 1 && s[0] == '0' && tmp->signe != '-' && tmp->zero == 0 && tmp->minus == 0)
					write(1, "+", 1);
				else if (tmp->zero == 0 && tmp->minus == 0 && s[0] != '0' && tmp->signe == '-')
					write(1, "-", 1);
			}
			ft_putstr(s);
			handle_minus(&tmp, &c, 1);
		}
	}
/*			else if (tmp->size == 66)
			{
			if ((char)l3 < 0)
			{
			tmp->signe = '-';
			l2  *= -1;
			}
			tmp->string = ft_test_itoa_unsigned_base((char)l3, 10, 'X');
			}
			else if (tmp->size == 1)
			{
			if ((long int)l3 < 0)
			{
			tmp->signe = '-';
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
			write(1, "+", 1);
		}
		if ((tmp->plus == 1 || tmp->width != 0) && tmp->minus == 1 && tmp->zero == 0 && l < 0)
		{
			flag = 1;
			write(1, "-", 1);
		}
		if (tmp->plus == 1 && (tmp->zero == 1 || tmp->minus == 1) && tmp->width != 0 && l >= 0 && flag == 0)
			write(1, "+", 1);
		//		printf("%i\n", tmp->space);//check
		t = size_l(l);
//			printf("%d\n", l);
		if (tmp->space == 1 && tmp->plus == 0 && tmp->width == 0 && tmp->minus == 0 && l >= 0)
		{
			tmp->space = 0;
			write(1, " ", 1);
		}
		if (tmp->space == 1 && tmp->plus == 0 && (tmp->width == 0 || t >=  tmp->width) && tmp->minus == 0 && l >= 0)
		{
			tmp->space = 0;
			write(1, " ", 1);
		}
		if (tmp->space == 1 && l == 0 && tmp->width != 0)
		{
			write(1, " ", 1);
			tmp->width = tmp->width - 1;
		}
		//if (tmp->space == 1 && tmp->minus == 0 && tmp->width != 0 && l > 0 && tmp->zero != 0)
		//{
		//	write(1, " ", 1);
		//	tmp->width = tmp->width - 1;
		//}
		if (tmp->space == 1 && tmp->minus == 1 && tmp->width != 0 && l != 0 && l > 0)
		{
			write(1, " ", 1);
			tmp->width = tmp->width - 1;
		}
		if (tmp->space == 1 && tmp->width != 0 && l > 0 && tmp->zero == 1)
		{
			write(1, " ", 1);
			tmp->width = tmp->width - 1;
		}
		if (tmp->width == 0 && (tmp->minus == 1 || tmp->zero == 1) && l < 0 && flag == 0)
			write(1, "-", 1);
		if (l < 0)
			ul = l * -1;
		else
			ul = l;
		if (tmp->width >= 0)
		{
			t = size_l(ul);
			//		printf("%i %i %i\n", tmp->width, t, tmp->space);// check
			if (t >= tmp->width)
				tmp->width = 0;
			if (tmp->width > t)
			{
				tmp->width = tmp->width - t;
				if (tmp->plus == 1 || l < 0)
					tmp->width = tmp->width - 1;
			}
			//		printf("%i %i %i\n", tmp->nb, t, tmp->plus);// check
			if (tmp->zero == 1 && l < 0 && tmp->minus == 0)
				write(1, "-", 1);
			handle_minus(&tmp, &c, 0);
			if (tmp->plus == 1 && l >= 0 && tmp->zero == 0 && tmp->minus == 0)
				write(1, "+", 1);
			else if (tmp->zero == 0 && tmp->minus == 0 && l < 0)
				write(1, "-", 1);
			if (l < 0)
				l = l * -1;
		}
		ft_putnbr(l);
		handle_minus(&tmp, &c, 1);
	}
}
