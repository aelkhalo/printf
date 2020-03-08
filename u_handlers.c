/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:46:23 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/08 17:47:04 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    u_handler(pf *a, t_flags *b, va_list *ap)
{
    unsigned int i;
    int j;
    int val;
    int yes;
    int ex;
    
    i = va_arg(*ap, int);
    j = va_arg(*ap, int);
    yes = 0;
    ex = 0;
    check_d_hand0(b, j);
    if (i < 0 && (yes += 1 || 1))
    {
        if (b->wth.v == b->prec.v)
            b->wth.v += 1;
        i *= -1;
        b->wth.v -= 1;
        a->lenght++;
    }
    val = count_int(i);
    check_d_norme(a, b, val ,i);   
    if (yes && i > 0)
        ft_putchar('-');
    check_u_hand2(a, b, val, ex, i);
    cal_lenght(a, val);
}

void    check_u_hand2(pf *a, t_flags *b, int val, int ex, unsigned int i)
{
    if (val > b->prec.v && b->prec.v > 0 && b->wth.v == b->prec.v)
        b->wth.v = 0;
    else if (b->prec.v >= b->wth.v && b->wth.v > 0)
        b->wth.v = 0;
    if (b->prec.s == 1 && b->prec.v > val)
        print_zeros(&(*a), &(*b), val);
    else if (b->zero.s  && b->zero.v > val)
        print_zeros(&(*a), &(*b), val);
    if (b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
    {
        if (b->wth.v > 0)
            b->wth.v++;
        ex = 1;
        a->lenght--;
    }
    else if (!ex)
        ft_u_putnbr(i);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}