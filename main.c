#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	int		i;
	int		l;
	float	f;
	char	*c;
	char	a;
	int 	l2;

	l2 = -9898880;
	a = '3';
	c = "1";
	i = 0;
	l = 0;
	f = 343.1059884;

/*		%i / %d
 
	printf("Hello %i worlde!\n", i);
	ft_printf("Hello %i worlde!\n\n", i);

	printf("Hello % i worlde!\n", i);
	ft_printf("Hello % i worlde!\n\n", i);

	printf("Hello %+i worlde!\n", i);
	ft_printf("Hello %+i worlde!\n\n", i);

	printf("Hello %2i worlde!\n", i);
	ft_printf("Hello %2i worlde!\n\n", i);

	printf("Hello % 2i worlde!\n", i);
	ft_printf("Hello % 2i worlde!\n\n", i);

	printf("Hello %02i worlde!\n", i);
	ft_printf("Hello %02i worlde!\n\n", i);

	printf("Hello %-i worlde!\n", i);
	ft_printf("Hello %-i worlde!\n\n", i);

	printf("Hello %-2i worlde!\n", i);
	ft_printf("Hello %-2i worlde!\n\n", i);

	printf("Hello %+-2i worlde!\n", i);
	ft_printf("Hello %+-2i worlde!\n\n", i);

	printf("Hello %+-i worlde!\n", i);
	ft_printf("Hello %+-i worlde!\n\n", i);

	printf("Hello %+2i worlde!\n", i);
	ft_printf("Hello %+2i worlde!\n\n", i);

	printf("Hello % 02i worlde!\n", i);
	ft_printf("Hello % 02i worlde!\n\n", i);

	printf("Hello % -2i worlde!\n", i);
	ft_printf("Hello % -2i worlde!\n", i);
*/
/*		%o
 
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

//		%X
 
	printf("%hhX\n", (signed char)l2);
	ft_printf("%hhX\n", (signed char)l2);

/*	printf("%X\n", 0);
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
