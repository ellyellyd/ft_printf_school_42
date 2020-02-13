/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:00:09 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 04:15:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	int		l;
	float	f;
	char	*c;
	char	a;

	unsigned int 	l2;

	unsigned int		l3;
	unsigned long int		l4;
	long long int	l5;

	l5 = 896;//

	l4 = -9779;

	l3 = 0;

	l2 = 0;

	a = '3';
	c = "1";
	i = 4;
	l = 0;
	f = 343.1059884;

/*		%s
	printf("%s\n", "hsdjf skfh Fis sfiFl   ");
	ft_printf("%s\n", "hsdjf skfh Fis sfiFl   ");
*/
/*		%c
	printf("%c\n", a);
	ft_printf("%c\n", a);
*/
//		%i / %d
//

	//printf("%5\n");
	//printf("%5\n\n");

	printf("TEST 148:\n");

	printf("or_printf: \n");
	printf("%d %d", 1, -2);
	printf("\n\n\n");

	printf("ft_printf: \n");
	ft_printf("%d %d", 1, -2);
	printf("\n\n\n");


	/* printf("TEST 19:\n"); */

	/* printf("or_printf: "); */
	/* printf("%X", 4294967296); */
	/* printf("\n\n\n"); */

	/* printf("ft_printf: "); */
	/* ft_printf("%X", 4294967296); */
	/* printf("\n\n\n"); */

/* 	printf("%li\n", l4); */
/* 	ft_printf("%li\n\n", l4);// it does not work with long int and negativ int */

/* 	printf("%hhi\n", (char)l4); */
/* 	ft_printf("%hhi\n\n", (char)l4); */
/* // */
/* 	printf("Hello %-+6i worlde!\n", i); */
/* 	ft_printf("Hello %-+6i worlde!\n\n", i); */

/* 	printf("Hello %i worlde!\n", i); */
/* 	ft_printf("Hello %i worlde!\n\n", i); */

/* 	printf("Hello % i worlde!\n", i); */
/* 	ft_printf("Hello % i worlde!\n\n", i); */

/* 	printf("Hello %+i worlde!\n", i); */
/* 	ft_printf("Hello %+i worlde!\n\n", i); */

/* 	printf("Hello %6i worlde!\n", i); */
/* 	ft_printf("Hello %6i worlde!\n\n", i); */

/* 	printf("Hello % 6i worlde!\n", i); */
/* 	ft_printf("Hello % 6i worlde!\n\n", i); */

/* 	printf("Hello %06i worlde!\n", i); */
/* 	ft_printf("Hello %06i worlde!\n\n", i); */

/* 	printf("Hello %-i worlde!\n", i); */
/* 	ft_printf("Hello %-i worlde!\n\n", i); */

/* 	printf("Hello %-6i worlde!\n", i); */
/* 	ft_printf("Hello %-6i worlde!\n\n", i); */

/* 	printf("Hello %+-6i worlde!\n", i); */
/* 	ft_printf("Hello %+-6i worlde!\n\n", i); */

/* 	printf("Hello %+-i worlde!\n", i); */
/* 	ft_printf("Hello %+-i worlde!\n\n", i); */

/* 	printf("Hello %+6i worlde!\n", i); */
/* 	ft_printf("Hello %+6i worlde!\n\n", i); */

/* 	printf("Hello % 06i worlde!\n", i); */
/* 	ft_printf("Hello % 06i worlde!\n\n", i); */

/* 	printf("Hello % -6i worlde!\n", i); */
/* 	ft_printf("Hello % -6i worlde!\n", i); */
//
/*		%o

	printf("%ho\n", (unsigned short int)l2);
	ft_printf("%ho\n", (unsigned short int)l2);
	printf("%hho\n", (unsigned char)l2);
	ft_printf("%hho\n", (unsigned char)l2);

	printf("%ho\n", (short int)l2);
	ft_printf("%ho\n", (short int)l2);
	printf("%hho\n", (signed char)l2);
	ft_printf("%hho\n", (signed char)l2);
*//*
	printf("%lo\n", l4);
	ft_printf("%lo\n", l4);
	printf("%llo\n", l5);
	ft_printf("%llo\n", l5);
  */

/*
	printf("%o\n", 0);
	ft_printf("%o\n", 0);
	printf("%o\n", 18);
	ft_printf("%o\n", 18);
	printf("%o\n", -98);
	ft_printf("%o\n", -98);

	printf("%8o\n", 0);
	ft_printf("%8o\n", 0);
	printf("%8o\n", 18);
	ft_printf("%8o\n", 18);
	printf("%8o\n", -98);
	ft_printf("%8o\n", -98);

	printf("%-8o\n", 0);
	ft_printf("%-8o\n", 0);
	printf("%-8o\n", 18);
	ft_printf("%-8o\n", 18);
	printf("%-8o\n", -98);
	ft_printf("%-8o\n", -98);

	printf("%00o\n", 0);
	ft_printf("%00o\n", 0);
	printf("%06o\n", 0);
	ft_printf("%06o\n", 0);
	printf("%08o\n", 18);
	ft_printf("%08o\n", 18);
	printf("%08o\n", -98);
	ft_printf("%08o\n", -98);


	printf("%#o\n", 0);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 18);
	ft_printf("%#o\n", 18);
	printf("%#o\n", -98);
	ft_printf("%#o\n", -98);

	printf("%#8o\n", 0);
	ft_printf("%#8o\n", 0);
	printf("%#8o\n", 18);
	ft_printf("%#8o\n", 18);
	printf("%#8o\n", -98);
	ft_printf("%#8o\n", -98);

	printf("%#-8o\n", 0);
	ft_printf("%#-8o\n", 0);
	printf("%#-8o\n", 18);
	ft_printf("%#-8o\n", 18);
	printf("%#-8o\n", -98);
	ft_printf("%#-8o\n", -98);

	printf("%00#o\n", 0);
	ft_printf("%00#o\n", 0);
	printf("%#06o\n", 0);
	ft_printf("%#06o\n", 0);
	printf("%#08o\n", 18);
	ft_printf("%#08o\n", 18);
	printf("%#08o\n", -98);
	ft_printf("%#08o\n", -98);
*/

/*		%u
//
	printf("%hu\n", (unsigned short int)l2);
	ft_printf("%hu\n", (unsigned short int)l2);
	printf("%hhu\n", (unsigned char)l2);
	ft_printf("%hhu\n", (unsigned char)l2);

	printf("%hu\n", (short int)l2);
	ft_printf("%hu\n", (short int)l2);
	printf("%hhu\n", (signed char)l2);
	ft_printf("%hhu\n", (signed char)l2);
//
	printf("%lu\n", l4);
	ft_printf("%lu\n", l4);
	printf("%llu\n", l5);
	ft_printf("%llu\n", l5);
//
//
	printf("%u\n", 0);
	ft_printf("%u\n", 0);
	printf("%u\n", 18);
	ft_printf("%u\n", 18);
	printf("%u\n", -98);
	ft_printf("%u\n", -98);

	printf("%8u\n", 0);
	ft_printf("%8u\n", 0);
	printf("%8u\n", 18);
	ft_printf("%8u\n", 18);
	printf("%8u\n", -98);
	ft_printf("%8u\n", -98);

	printf("%-8u\n", 0);
	ft_printf("%-8u\n", 0);
	printf("%-8u\n", 18);
	ft_printf("%-8u\n", 18);
	printf("%-8u\n", -98);
	ft_printf("%-8u\n", -98);

	printf("%00u\n", 0);
	ft_printf("%00u\n", 0);
	printf("%06u\n", 0);
	ft_printf("%06u\n", 0);
	printf("%08u\n", 18);
	ft_printf("%08u\n", 18);
	printf("%08u\n", -98);
	ft_printf("%08u\n", -98);
*/

/*		%X

	printf("%lX\n", l4);
	ft_printf("%lX\n", l4);
	printf("%llX\n", l5);
	ft_printf("%llX\n", l5);

	printf("%hX\n", (unsigned short int)l3);
	ft_printf("%hX\n", (unsigned short int)l3);
	printf("%hhX\n", (unsigned char)l3);
	ft_printf("%hhX\n", (unsigned char)l3);

	printf("%hX\n", (short int)l2);
	ft_printf("%hX\n", (short int)l2);
	printf("%hhX\n", (signed char)l2);
	ft_printf("%hhX\n", (signed char)l2);
//
//
	printf("%X\n", 0);
	ft_printf("%X\n", 0);
	printf("%X\n", 18);
	ft_printf("%X\n", 18);
	printf("%X\n", -98);
	ft_printf("%X\n", -98);

	printf("%8X\n", 0);
	ft_printf("%8X\n", 0);
	printf("%8X\n", 18);
	ft_printf("%8X\n", 18);
	printf("%8X\n", -98);
	ft_printf("%8X\n", -98);

	printf("%-8X\n", 0);
	ft_printf("%-8X\n", 0);
	printf("%-8X\n", 18);
	ft_printf("%-8X\n", 18);
	printf("%-8X\n", -98);
	ft_printf("%-8X\n", -98);

	printf("%00X\n", 0);
	ft_printf("%00X\n", 0);
	printf("%06X\n", 0);
	ft_printf("%06X\n", 0);
	printf("%08X\n", 18);
	ft_printf("%08X\n", 18);
	printf("%08X\n", -98);
	ft_printf("%08X\n", -98);


	printf("%#X\n", 0);
	ft_printf("%#X\n", 0);
	printf("%#X\n", 18);
	ft_printf("%#X\n", 18);
	printf("%#X\n", -98);
	ft_printf("%#X\n", -98);

	printf("%#8X\n", 0);
	ft_printf("%#8X\n", 0);
	printf("%#8X\n", 18);
	ft_printf("%#8X\n", 18);
	printf("%#8X\n", -98);
	ft_printf("%#8X\n", -98);

	printf("%#-8X\n", 0);
	ft_printf("%#-8X\n", 0);
	printf("%#-8X\n", 18);
	ft_printf("%#-8X\n", 18);
	printf("%#-8X\n", -98);
	ft_printf("%#-8X\n", -98);

	printf("%00#X\n", 0);
	ft_printf("%00#X\n", 0);
	printf("%#06X\n", 0);
	ft_printf("%#06X\n", 0);
	printf("%#08X\n", 18);
	ft_printf("%#08X\n", 18);
	printf("%#08X\n", -98);
	ft_printf("%#08X\n", -98);
*/

/*		%x

//
	printf("%lx\n", l4);
	ft_printf("%lx\n", l4);
//
	printf("%llx\n", l5);
	ft_printf("%llx\n", l5);
//

//
	printf("%hx\n", (unsigned short int)l2);
	ft_printf("%hx\n", (unsigned short int)l2);
	printf("%hhx\n", (unsigned char)l2);
	ft_printf("%hhx\n", (unsigned char)l2);

	printf("%hx\n", (short int)l2);
	ft_printf("%hx\n", (short int)l2);
	printf("%hhx\n", (signed char)l2);
	ft_printf("%hhx\n", (signed char)l2);
//
//
	printf("%x\n", 0);
	ft_printf("%x\n", 0);
	printf("%x\n", 18);
	ft_printf("%x\n", 18);
	printf("%x\n", -98);
	ft_printf("%x\n", -98);

	printf("%8x\n", 0);
	ft_printf("%8x\n", 0);
	printf("%8x\n", 18);
	ft_printf("%8x\n", 18);
	printf("%8x\n", -98);
	ft_printf("%8x\n", -98);

	printf("%-8x\n", 0);
	ft_printf("%-8x\n", 0);
	printf("%-8x\n", 18);
	ft_printf("%-8x\n", 18);
	printf("%-8x\n", -98);
	ft_printf("%-8x\n", -98);

	printf("%00x\n", 0);
	ft_printf("%00x\n", 0);
	printf("%06x\n", 0);
	ft_printf("%06x\n", 0);
	printf("%08x\n", 18);
	ft_printf("%08x\n", 18);
	printf("%08x\n", -98);
	ft_printf("%08x\n", -98);



	printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	printf("%#x\n", 18);
	ft_printf("%#x\n", 18);
	printf("%#x\n", -98);
	ft_printf("%#x\n", -98);

	printf("%#8x\n", 0);
	ft_printf("%#8x\n", 0);
	printf("%#8x\n", 18);
	ft_printf("%#8x\n", 18);
	printf("%#8x\n", -98);
	ft_printf("%#8x\n", -98);

	printf("%#-8x\n", 0);
	ft_printf("%#-8x\n", 0);
	printf("%#-8x\n", 18);
	ft_printf("%#-8x\n", 18);
	printf("%#-8x\n", -98);
	ft_printf("%#-8x\n", -98);

	printf("%00#x\n", 0);
	ft_printf("%00#x\n", 0);
	printf("%#06x\n", 0);
	ft_printf("%#06x\n", 0);
	printf("%#08x\n", 18);
	ft_printf("%#08x\n", 18);
	printf("%#08x\n", -98);
	ft_printf("%#08x\n", -98);
*/

/*		%p

	printf("%-9p\n", c);
	ft_printf("%-9p\n", c);
*/

/*		%f

	printf("%f\n", f);
	ft_printf("%f\n", f);
*/
	return (0);
}
