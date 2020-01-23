#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	a10_in_8(int l);
void	x_10_in_16(int l);
char	*ft_itoa_base(int value, int base);
char	*X_ft_itoa_base(int value, int base);
char	*ft_itoa_unsigned_base(unsigned int value, int base, char c);
