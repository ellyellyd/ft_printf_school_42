#include "libftprintf.h"

char	*ft_ftoa(long double value)
{
	size_t		size;
	char		*tab;
	char		*s;

	size = 0;
	tab = "0123456789";
	value /= 10;
	if (value > 0)
		ft_ftoa(value);
	else
	{
		s = (char *)ft_memalloc(size + 1);
		s[size] = '\0';
		
	}
}

char	*get_s_and_mod_w_f(t_frm *tmp, va_list argptr)
{
	char			*s;
	long double		value_ld;
	double			value_d;
	float			value_f;

	if (tmp->size == 10)
		value_ld = va_arg(argptr, long double);
	else if (tmp->size == 11)
		value_d = va_arg(argptr, double);
	else if (tmp->size == 0)
		value_f = (float)va_arg(argptr, double);

	return (NULL);
}

void	handle_f(t_frm *tmp, va_list argptr)
{
	get_s_and_mod_w_f(tmp, argptr);
	/* t = ft_strlen(s); */
	/* printf("***s = %s\n***", s); */
	/* handle_zero_id(tmp, t); */
	/* print_string_id(tmp, s, t); */
	/* handle_minus_id(tmp, t); */
	/* ft_strdel(&s); */
}
