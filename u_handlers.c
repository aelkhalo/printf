/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:46:42 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 01:49:51 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_handler(t_pf *a, t_flags *b, va_list *ap)
{
	unsigned int	i;
	int				val;
	int				yes;

	i = va_arg(*ap, unsigned int);
	yes = 0;
	check_u_hand0(b, i);
	val = count_int(i);
	check_d_norme(a, b, val, i);
	if (yes && i > 0)
		ft_putchar('-');
	check_u_hand2(a, b, val, i);
	cal_lenght(a, val);
}

void	check_u_hand0(t_flags *b, int i)
{
	if (b->min.v && i < 0 && b->prec.s && b->check.s < b->prec.v)
		b->zero.v += 1;
	if (b->wth.v < 0)
	{
		b->wth.s = -1;
		b->wth.v *= -1;
	}
}

void	check_u_hand1(t_pf *a, t_flags *b, int val)
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

void	check_u_hand2(t_pf *a, t_flags *b, int val, unsigned int i)
{
	int ex;

	ex = 0;
	check_u_hand1(a, b, val);
	if (b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
	{
		if (b->wth.v > 0)
			b->wth.v++;
		ex = 1;
		a->lenght--;
	}
	else if (!ex)
		ft_u_putnbr(i);
	if (b->wth.s == 0 && b->wth.v == 0 && b->zero.s && b->zero.v < 0)
	{
		b->zero.v *= -1;
		b->wth.v = b->zero.v;
		b->wth.s = -1;
	}
	if (b->wth.s == -1)
		print_spaces(&(*a), &(*b), val);
}
