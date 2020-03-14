/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:22:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 00:02:35 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_handler(t_pf *a, t_flags *b, va_list *ap)
{
	unsigned long long	i;
	int					val;
	int					yes;
	int					ex;

	i = va_arg(*ap, unsigned long long);
	yes = 0;
	ex = 0;
	if (b->wth.v < 0)
		b->wth.v *= -1;
	if (i == 0)
	{
		b->wth.v++;
		a->lenght--;
	}
	check_x_hand0(b, i);
	val = count_hex(i, 1) + (!i ? 1 : 0);
	val += 2;
	check_d_norme(a, b, val, i);
	ft_putnstr("0x", 2);
	check_p_hand2(a, b, val, i);
	cal_lenght(a, val);
}

void	check_p_hand2(t_pf *a, t_flags *b, int val, unsigned long long i)
{
	int ex;

	ex = 0;
	check_x_hand3(a, b, val);
	if (b->zero.v == 0 && i == 0 && b->prec.v >= 0 && b->prec.s == 1)
	{
		if (b->wth.v > 0)
			b->wth.v++;
		ex = 1;
		a->lenght--;
	}
	if (ex == 0)
		ft_puthex(i, 0);
	if (b->wth.s == -1)
		print_spaces(&(*a), &(*b), val);
}
