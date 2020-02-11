#include "libftprintf.h"

void	fix_s(char *s, int *l, int cmp, int n)
{
	while (s[(*l)] == 'F')
		(*l)++;
	if ((*l) > cmp)
	{
		(*l) = n;
		while ((*l) >= 0)
			s[(*l)--] = ' ';
		(*l) = 0;
		while(s[n + 1 + (*l)] != '\0')
		{
			s[(*l)] = s[n + 1 + (*l)];
			(*l)++;
		}
		s[(*l)] = '\0';
		(*l) = 0;
	}
}
