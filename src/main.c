/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:00:09 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/22 09:42:31 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	printf("or_printf: ");
	printf("%f\n", -3.14);
	printf("ft_printf: ");
	ft_printf("%f\n", -3.14);
	/* printf("sizeof(float) = %zu\n", sizeof(float)); */
	/* printf("sizeof(double) = %zu\n", sizeof(double)); */
	/* printf("sizeof(long double) = %zu\n", sizeof(long double)); */
	return (0);
}
