/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:15:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 00:01:09 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_handler(t_pf *a, t_flags *b, va_list *ap)
{
	int val;
	int i;

	i = va_arg(*ap, int);
	val = 1;
	if (b->wth.v < 0)
	{
		b->wth.s = -1;
		b->wth.v *= -1;
	}
	if (b->wth.s == 1)
		print_spaces(&(*a), &(*b), val);
	ft_putchar(i);
	if (b->wth.s == -1)
		print_spaces(&(*a), &(*b), val);
}

void	perc_handler1(t_pf *a, t_flags *b, int val)
{
	if (b->zero.s == 1 && b->zero.v > 0 && b->prec.v >= 0 && b->check.s > 0)
	{
		b->zero.v = b->wth.v;
		print_zeros(&(*a), &(*b), val);
		b->wth.v = 0;
	}
	else if (b->zero.s == 1 && b->zero.v > 0 && b->prec.v == 0)
	{
		print_zeros(&(*a), &(*b), val);
		b->prec.v -= val;
		b->wth.v -= b->prec.v;
	}
}

void	perc_handler(t_pf *a, t_flags *b)
{
	int		val;
	char	i;

	i = '%';
	val = 1;
	if (b->wth.v < 0)
	{
		b->wth.s = -1;
		b->wth.v *= -1;
	}
	if (b->prec.v < 0)
		b->prec.v *= -1;
	perc_handler1(a, b, val);
	if (b->wth.s == 1)
		print_spaces(&(*a), &(*b), val);
	ft_putchar(i);
	if (b->wth.s == -1)
		print_spaces(&(*a), &(*b), val);
}

void	f_handler(t_pf *a, t_flags *b, va_list *ap)
{
	if (*(a->buff) == 'd' || *(a->buff) == 'i')
		d_handler(&(*a), &(*b), ap);
	if (*(a->buff) == 'u')
		u_handler(&(*a), &(*b), ap);
	if (*(a->buff) == 'c')
		c_handler(&(*a), &(*b), ap);
	if (*(a->buff) == 's')
		s_handler(&(*a), &(*b), ap);
	if (*(a->buff) == '%')
		perc_handler(&(*a), &(*b));
	if (*(a->buff) == 'x' || *(a->buff) == 'X')
		x_handler(&(*a), &(*b), ap);
	if (*(a->buff) == 'p')
		p_handler(&(*a), &(*b), ap);
}
