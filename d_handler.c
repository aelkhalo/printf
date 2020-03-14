/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:47:08 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 01:47:12 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_d_hand(t_pf *a, t_flags *b, int val, int i)
{
	if (b->wth.v > 0 && b->wth.s && b->zero.v == 0 &&
			i == 0 && b->prec.v == 0 && b->prec.s)
		b->wth.v++;
	else if (b->min.v && i == 0 && b->prec.s && b->zero.v > b->prec.v &&
			b->wth.s && b->wth.v < b->prec.v)
		b->wth.v++;
	else if (b->min.v == 1 && i == 0 && b->prec.s &&
			b->zero.v > b->prec.v && b->wth.s)
		b->wth.v++;
	if (b->prec.v < 0 && b->wth.v > 0 && b->zero.v > 0)
	{
		b->wth.v = 0;
		if (b->prec.v < 0)
			b->prec.v *= -1;
	}
	print_spaces(&(*a), &(*b), val);
}

void	check_d_hand1(t_pf *a, t_flags *b, int val, int i)
{
	if (b->wth.v > 0 && b->wth.s && b->zero.v == 0 &&
			i == 0 && b->prec.v == 0 && b->prec.s)
		b->wth.v++;
	print_spaces(&(*a), &(*b), val);
	b->zero.v = b->prec.v;
}

void	check_d_hand3(t_pf *a, t_flags *b, int val)
{
	if (val > b->prec.v && b->prec.v > 0 && b->wth.v == b->prec.v)
		b->wth.v = 0;
	else if (b->prec.v >= b->wth.v && b->wth.v > 0)
		b->wth.v = 0;
	if (b->prec.s == 1 && b->prec.v > val && b->min.s && b->wth.s == -1)
	{
		b->zero.v = b->prec.v;
		print_zeros(&(*a), &(*b), val);
		b->prec.v -= val;
		b->wth.v -= b->prec.v;
	}
	else if (b->prec.s == 1 && b->prec.v > val)
	{
		print_zeros(&(*a), &(*b), val);
		b->prec.v -= val;
		b->wth.v -= b->prec.v;
	}
	else if (b->zero.s && b->zero.v > val)
		print_zeros(&(*a), &(*b), val);
}

void	check_d_hand2(t_pf *a, t_flags *b, int yes, int i)
{
	int ex;
	int val;

	ex = 0;
	val = count_int(i);
	check_d_hand3(a, b, val);
	if (b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
	{
		if (b->wth.v > 0)
			b->wth.v++;
		ex = 1;
		a->lenght--;
	}
	else if (!ex)
		ft_putnbr(i);
	if (b->wth.s == 0 && b->wth.v == 0 && b->zero.s && b->zero.v < 0)
	{
		b->zero.v *= -1;
		if (yes)
			b->zero.v -= val;
		b->wth.v = b->zero.v;
		b->wth.s = -1;
	}
	if (b->wth.s == -1)
		print_spaces(&(*a), &(*b), val);
}
