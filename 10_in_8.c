#include <libftprintf.h>

void	a8_nb_to_char(int l);

void	a10_in_8(int l)
{
	int		res;
	int		i;
	int		t;
	int		*tab;

	tab = (int*)malloc(sizeof(int) * 2147483647);
	res = l;
	t = 0;
	if (res < 8)
		a8_nb_to_char(l);
	else
	{
		while (res >= 8)
		{
			i = res % 8;
			res = res / 8;
			tab[t++] = i;
			if (res <= 8)
				tab[t] = res;
		}
		while (t >= 0)
		{
			a8_nb_to_char(tab[t]);
			t--;
		}
	}
}

void	a8_nb_to_char(int l)
{
	char	c;

	c = l + 48;
	write(1, &c, 1);
}
