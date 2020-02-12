/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_ft_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:20:10 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/02 23:20:18 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_abc(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

char	*X_ft_itoa_base(int value, int base)
{
	int		size;
	int		flag;
	int		tmp;
	char	*str;
	char	*tab;

	flag = 0;
	size = 0;
	tmp = value;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	while (tmp /= base)
		size++;
	size = size + 1 + flag;
	str = (char*)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		size--;
		str[size] = tab[ft_abc(value % base)];
		value /= base;
	}
	return (str);
}
