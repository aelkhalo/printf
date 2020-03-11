/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:07:08 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/11 02:17:44 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_d_norme(pf *a, t_flags *b, int val ,int i)
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
void    check_d_hand0(t_flags *b, int i)
{
    // if (b->min.s && i == 0 && b->prec.s)
    //     b->wth.s = 1;
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

void    check_d_hand(pf *a, t_flags *b, int val, int i)
{
    if (b->wth.v > 0 && b->wth.s && b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
        b->wth.v++;
    else if (b->min.v && i == 0 && b->prec.s && b->zero.v > b->prec.v && b->wth.s && b->wth.v < b->prec.v)
        b->wth.v++;
    else if (b->min.v == 1 && i == 0 && b->prec.s && b->zero.v > b->prec.v && b->wth.s)
        b->wth.v++;
    if (b->prec.v < 0 && b->wth.v > 0 && b->zero.v > 0)
    {
        b->wth.v = 0;
        if (b->prec.v < 0)
            b->prec.v *= -1;
    }
    print_spaces(&(*a), &(*b), val);
}

void    check_d_hand1(pf *a, t_flags *b, int val, int i)
{
    if (b->wth.v > 0 && b->wth.s && b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
        b->wth.v++;
    print_spaces(&(*a), &(*b), val);
    b->zero.v = b->prec.v;
}

void    check_d_hand2(pf *a, t_flags *b, int val, int ex, int i)
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
    if (b->zero.v == 0 && i == 0 && b->prec.v == 0 && b->prec.s)
    {
        if (b->wth.v > 0)
            b->wth.v++;
        ex = 1;
        a->lenght--;
    }
    else if (!ex)
        ft_putnbr(i);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}