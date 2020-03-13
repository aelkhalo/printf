/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 04:16:37 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/13 07:49:04 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    get_wth_min(pf *a, t_flags *b, va_list *ap)
{
    if (*a->buff == '-')
    {
        b->wth.s = -1;
        b->min.s = 1;
        while (*a->buff == '-')
            a->buff++;
        while (*a->buff == ' ')
            a->buff++;
        if (*a->buff == '*')
            b->wth.v = va_arg(*ap, int);
        else if (ft_isdigit(*a->buff) == 1)
        {
            b->wth.v = ft_atoi(a->buff);
            while (ft_isdigit(*a->buff))
                a->buff++;
            a->buff--;
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
    }
}

void    get_wth_dig(pf *a, t_flags *b)
{
    int i;

    i = 0;
    if (ft_isdigit(*a->buff) == 1)
    {
        b->wth.v = ft_atoi(a->buff);
        i = count_int(b->wth.v);
        while (i != 1)
        {
            a->buff++;
            i--;
        }
    }
}

void    get_wth(pf *a, t_flags *b, va_list *ap)
{   
    if (*a->buff == '-' || *a->buff == '*' || ft_isdigit(*a->buff))
    {
        b->wth.s = 1;
        if (*a->buff == '*')
            b->wth.v = va_arg(*ap, int);
        else if (*a->buff == '-')
            get_wth_min(a, b, ap);
        else if (ft_isdigit(*a->buff) == 1)
            get_wth_dig(a, b);
    }
    if (b->wth.v < 0)
        b->wth.s = -1;  
}

void    get_zero(pf *a,t_flags *b, va_list *ap)
{
    int  i;
    
    if (*a->buff == '0')
    {
        b->zero.s = 1;
        b->min.v = 1;
        a->buff++;
        while (*a->buff == ' ')
            a->buff++;
        if (*a->buff == '*')
            b->zero.v = va_arg(*ap, int);
        else if (*a->buff == '.')
            get_prec(a, b, ap);
        if (ft_isdigit(*a->buff) == 1)
        {
            b->zero.v = ft_atoi(a->buff);
            i = count_int(b->zero.v);
            while (i != 1)
            {
                a->buff++;
                i--;
            }
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
    }
}

void    get_prec(pf *a, t_flags *b, va_list *ap)
{
    int i;
    
    if (*a->buff == '.')
    {
        b->prec.s = 1;
        a->buff++;
        while (*a->buff == '0')
            a->buff++;
        if (*a->buff == '*')
            b->prec.v = va_arg(*ap, int);
        else if (ft_isdigit(*a->buff) == 1)
        {
            b->prec.v = ft_atoi(a->buff);
            i = count_int(b->prec.v);
            while (i != 1)
            {
                a->buff++;
                i--;
            }
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
        else if (*a->buff == '%')
            a->buff--;
    }
    if (b->zero.s == 1)
    {
        b->check.s = b->zero.v;
        b->wth.v = b->zero.v;
        b->wth.s = 1;
    }
    if (b->wth.v < b->prec.v)
        b->zero.v = b->prec.v;
}