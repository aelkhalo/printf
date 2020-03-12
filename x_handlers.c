/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 04:13:25 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/12 21:27:11 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void    x_handler(pf *a, t_flags *b, va_list *ap)
{
    unsigned int i;
    int val;
    int yes;
    int ex;
    
    i = va_arg(*ap, unsigned int);
    yes = 0;
    ex = 0;
    if (i == 0)
        d_x_handler(&(*a), &(*b), i);
    else
    {
        check_x_hand0(b, i);
        val = count_hex(i , b->prec.s);
        check_d_norme(a, b, val ,i);
        check_x_hand2(a, b, val, i);
        cal_lenght(a, val);
    }
}
void    d_x_handler(pf *a, t_flags *b, unsigned int i)
{
    int val;
    int yes;
    int ex;
    
    yes = 0;
    ex = 0;
    check_d_hand0(b, i);
    val = count_int(i);
    check_d_norme(a, b, val ,i);   
    if (yes && i > 0)
        ft_putchar('-');
    check_d_hand2(a, b, val, ex, i);
    cal_lenght(a, val);
}

void    check_x_hand0(t_flags *b, int i)
{
    if (b->min.v && i < 0 && b->prec.s && b->check.s < b->prec.v)
        b->zero.v += 1;
    if (b->wth.v < 0)
    {
        b->wth.s = -1;
        b->wth.v *= -1;
    }
}

void    check_x_hand2(pf *a, t_flags *b, int val, unsigned int i)
{
    int maj;
    int ex;
    
    ex = 0;
    if (*a->buff == 'x')
        maj = 0;
    else
        maj = 1;
    check_x_hand3(a, b, val);
    if (b->zero.v == 0 && i == 0 && b->prec.v >= 0 && b->prec.s == 1)
    {
        if (b->wth.v > 0)
            b->wth.v++;
        ex = 1;
        a->lenght--;
    }
    if (ex == 0)
        ft_puthex(i, maj);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}

void    check_x_hand3(pf *a, t_flags *b, int val)
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
        print_zeros(&(*a), &(*b), val);
    else if (b->zero.s  && b->zero.v > val)
        print_zeros(&(*a), &(*b), val);
}