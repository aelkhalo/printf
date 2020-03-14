/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:46:29 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 01:50:21 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zeros(t_pf *a, t_flags *b, int val)
{
	if (b->zero.v >= val)
	{
		b->zero.v -= val;
		while (b->zero.v != 0)
		{
			ft_putchar('0');
			b->zero.v--;
			a->lenght++;
			if (b->zero.v < 0)
				break ;
		}
	}
}

void	print_s_spaces(t_pf *a, t_flags *b)
{
	while (b->wth.v > 0)
	{
		ft_putchar(' ');
		b->wth.v--;
		a->lenght++;
		if (b->wth.v < 0)
			break ;
	}
	b->zero.v = b->prec.v;
}

void	print_spaces(t_pf *a, t_flags *b, int val)
{
	if (b->wth.v >= val)
	{
		b->wth.v -= val;
		while (b->wth.v != 0)
		{
			ft_putchar(' ');
			b->wth.v--;
			a->lenght++;
			if (b->wth.v < 0)
				break ;
		}
		b->zero.v = b->prec.v;
	}
}
