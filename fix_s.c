#include "libftprintf.h"

void	fix_s(char *s, char c, int cmp, int n)
{
	int		l;

	l = 0;
	while (s[l] == c)
		l++;
	if (l > cmp)
	{
		l = n;
		while (l >= 0)
			s[l--] = ' ';
		l = 0;
		while(s[n + 1 + l] != '\0')
		{
			s[l] = s[n + 1 + l];
			l++;
		}
		s[l] = '\0';
		l = 0;
	}
}
