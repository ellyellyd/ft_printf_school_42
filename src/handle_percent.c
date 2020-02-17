/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:40:02 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/13 09:13:23 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_percent(t_frm *tmp)
{
  int		i;

  i = 0;
  if (tmp->w > 1)
  {
    i = tmp->w - 1;
    if (tmp->minus == 0)
    {
      while (i > 0)
      {
        ft_putchar(' ');
        tmp->ret += 1;
        i--;
      }
    }
    ft_putchar('%');
    tmp->ret += 1;
    if (tmp->minus == 1)
    {
      while (i > 0)
      {
        ft_putchar(' ');
        tmp->ret += 1;
        i--;
      }
    }
  }
  else
  {
    ft_putchar('%');
    tmp->ret += 1;
  }
}
