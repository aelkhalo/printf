/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:32:28 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/13 08:17:14 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        s_handler(pf *a, t_flags *b, va_list *ap)
{
    char *s;
    int val;
    int ex;
    
    s = va_arg(*ap, char*);
    ex = 0;
    if (!s)
    {
		s = "(null)";
        ex = 1;
    }
    val = ft_strlen(s);
    check_s_hand1(a, b, val);
    check_s_hand(a, b, val);
    check_s_hand2(a, b, val, s);
    a->lenght--;
}

void    check_s_hand(pf *a, t_flags *b, int val)
{
    if (b->wth.s == 1 && val == b->prec.v && val < b->wth.v && b->prec.s == 0)
    {
        b->wth.v += val;
        print_s_spaces(&(*a), &(*b));
    }
    else if (b->wth.s == 1 && b->wth.v > b->prec.v && b->prec.s == 1)
    {
        b->wth.v -= b->prec.v ;
        print_s_spaces(&(*a), &(*b));
    }
    else if (b->wth.v > b->prec.v && b->prec.s && b->wth.s == 1 && b->prec.s == 1)
    {
        b->wth.v -= b->prec.v;
        print_s_spaces(&(*a), &(*b));
    }
    else if (b->wth.s == 1 && b->prec.v > b->wth.v && val <= b->prec.v && b->prec.s == 1)
    {
        b->wth.v = 0;
        print_s_spaces(&(*a), &(*b));
    }
}

void    check_s_hand2(pf *a, t_flags *b, int val, char *s)
{
    if (b->prec.v < val && b->prec.s == 1)
    {
        ft_putstr(s, b->prec.v, a);
        b->wth.v -= b->prec.v;
    }
    else
    {
        ft_putstr(s, val, a);
        b->wth.v -= val;
    }
    if (b->wth.v < 0)
    {
        b->wth.v *= -1;
        b->wth.v -= val;
    }
    if (b->prec.v < val)
        b->prec.v += val;
    if (b->wth.s == -1)
        print_s_spaces(&(*a), &(*b));
}

void    check_s_hand1(pf *a, t_flags *b, int val)
{
    if (b->wth.v < 0)
        b->wth.v *= -1;
    if (b->prec.v < 0)
        b->prec.v = val;
    if (b->wth.s == 1 && val < b->prec.v && val < b->wth.v && b->prec.s == 1)
    {
        b->wth.v -= val;
        print_s_spaces(&(*a), &(*b));
    }
    else if (b->wth.s == 1 && val > b->prec.v && val < b->wth.v && b->prec.s == 0)
    {
        b->wth.v -= val;
        print_s_spaces(&(*a), &(*b));
    }
}
