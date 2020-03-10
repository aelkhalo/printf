/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:15:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/10 18:36:04 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    c_handler(pf *a, t_flags *b, va_list *ap)
{
    int val;
    int i;
    
    i = va_arg(*ap, int);
    val = 1;
    if (b->wth.v < 0){
        b->wth.s = -1;
        b->wth.v *= -1;
    }
    if (b->wth.s == 1)
        print_spaces(&(*a), &(*b), val);
    ft_putchar(i);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}

void    perc_handler(pf *a, t_flags *b)
{
    int val;
    char i;
    
    i = '%';
    val = 1;
    if (b->wth.v < 0){
        b->wth.s = -1;
        b->wth.v *= -1;
    }
    if (b->prec.v < 0)
        b->prec.v *= -1;
    if (b->zero.s == 1 && b->zero.v > 0 && b->prec.v >= 0 && b->check.s > 0)
    {
        b->zero.v = b->wth.v;
        print_zeros(&(*a), &(*b), val);
        b->wth.v = 0;
    }
    if (b->wth.s == 1)
        print_spaces(&(*a), &(*b), val);
    ft_putchar(i);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}

void    d_handler(pf *a, t_flags *b, va_list *ap)
{
    int i;
    int val;
    int yes;
    int ex;
    
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
    check_d_norme(a, b, val ,i);   
    if (yes && i > 0)
        ft_putchar('-');
    check_d_hand2(a, b, val, ex, i);
    cal_lenght(a, val);
}

void    cal_lenght(pf *a, int val)
{
    if (val > 1)
    {
        while (val != 1)
        {
            a->lenght++;
            val--;
        }
    }
}

void    x_handler(pf *a, t_flags *b, va_list *ap)
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
    val = count_hex(i ,b);
    check_d_norme(a, b, val ,i);
    check_x_hand2(a, b, val, ex, i);
    if (val == 0)
        a->lenght--;
    cal_lenght(a, val);
}


void    check_x_hand2(pf *a, t_flags *b, int val, int ex, unsigned int i)
{
    int maj;
    
    if (*a->buff == 'x')
        maj = 0;
    else
        maj = 1;
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
    else if (!ex && i != 0)
        ft_puthex(i, maj);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
}

void    f_handler(pf *a, t_flags *b, va_list *ap)
{
    // char    *s;
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
    // else if (*(a->buff) == 'p')
    // {
    //     s = va_arg(*ap, char*);
    // }
}