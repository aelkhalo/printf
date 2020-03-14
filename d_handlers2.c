/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handlers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:19:41 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 00:01:36 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_handler(t_pf *a, t_flags *b, va_list *ap)
{
	int	i;
	int	val;
	int	yes;
	int	ex;

	i = va_arg(*ap, int);
	yes = 0;
	ex = 0;
	check_d_hand0(b, i);
	if (i < 0 && (yes += 1 || 1))
	{
		if (b->wth.v == b->prec.v)
			b->wth.v += 1;
		i *= -1;
		b->wth.v -= 1;
		a->lenght++;
	}
	val = count_int(i);
	check_d_norme(a, b, val, i);
	if (yes && i > 0)
		ft_putchar('-');
	check_d_hand2(a, b, yes, i);
	cal_lenght(a, val);
}

void	check_d_norme(t_pf *a, t_flags *b, int val, int i)
{
	if (b->wth.s == 1 && b->wth.v >= b->prec.v && b->prec.v > val && b->prec.s)
	{
		b->wth.v += val;
		b->wth.v -= b->prec.v;
		b->check.s = 1;
	}
	if (b->wth.s == 1 && b->prec.v <= b->wth.v)
		check_d_hand(a, b, val, i);
	else if (b->wth.s && b->prec.v > b->wth.v && b->check.s == 1)
		check_d_hand1(a, b, val, i);
	else if (!b->wth.s)
		print_spaces(&(*a), &(*b), val);
}

void	check_d_hand0(t_flags *b, int i)
{
	if (b->min.v && i < 0 && b->prec.s && b->check.s < b->prec.v)
		b->zero.v += 1;
	if (b->wth.v < 0)
	{
		b->wth.s = -1;
		b->wth.v *= -1;
	}
	if (i < 0 && b->zero.s)
		b->zero.v -= 1;
}
