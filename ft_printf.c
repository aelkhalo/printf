/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:50:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 00:11:09 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_pf *a, t_flags *b, va_list *ap)
{
	a->flags = a->buff;
	while (*a->buff != 'c' && *a->buff != 's' && *a->buff != 'p' &&
			*a->buff != 'd' && *a->buff != 'i' && *a->buff != 'u' &&
			*a->buff != 'x' && *a->buff != 'X' && *a->buff != '%')
	{
		while (*a->buff == ' ')
			a->buff++;
		if (*a->buff == '0')
			get_zero(a, b, ap);
		else if (*a->buff == '-' || *a->buff == '*' ||
				ft_isdigit(*a->buff) == 1)
			get_wth(a, b, ap);
		if (*a->buff == '.')
			get_prec(a, b, ap);
		a->buff++;
	}
	f_handler(a, b, ap);
}

void	get_in(t_pf *a, t_flags *b)
{
	b->wth.s = 0;
	b->wth.v = 0;
	b->zero.s = 0;
	b->zero.v = 0;
	b->prec.s = 0;
	b->prec.v = 0;
	b->min.s = 0;
	b->min.v = 0;
	b->check.s = 0;
	b->check.v = 0;
	a->lenght = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_pf		a;
	t_flags		b;

	va_start(ap, str);
	a.buff = (char *)str;
	get_in(&a, &b);
	while (*a.buff)
	{
		if (*a.buff == '%')
		{
			a.buff++;
			get_flags(&a, &b, &ap);
			a.buff++;
			a.lenght++;
		}
		else
		{
			write(1, a.buff, 1);
			a.buff++;
			a.lenght++;
		}
	}
	va_end(ap);
	return (a.lenght);
}
