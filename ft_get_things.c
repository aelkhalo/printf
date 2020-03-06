/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 04:16:37 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/06 08:27:24 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    get_wth_min(pf *a, t_flags *b, va_list *ap)
{
    if (*a->buff == '-')
    {
        b->wth.state = -1;
        b->min.state = 1;
        while (*a->buff == '-')
            a->buff++;
        while (*a->buff == ' ')
            a->buff++;
        if (*a->buff == '*')
            b->wth.value = va_arg(*ap, int);
        else if (ft_isdigit(*a->buff) == 1)
        {
            b->wth.value = ft_atoi(a->buff);
            while (ft_isdigit(*a->buff))
                a->buff++;
            a->buff--;
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
        // else if (*a->buff == '.')
        //     b->wth.state = 2;
    }
}

void    get_wth_dig(pf *a, t_flags *b)
{
    int i;

    i = 0;
    if (ft_isdigit(*a->buff) == 1)
    {
        b->wth.value = ft_atoi(a->buff);
        i = count_int(b->wth.value);
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
        b->wth.state = 1;
        if (*a->buff == '*')
            b->wth.value = va_arg(*ap, int);
        else if (*a->buff == '-')
            get_wth_min(a, b, ap);
        else if (ft_isdigit(*a->buff) == 1)
            get_wth_dig(a, b);
    }
    if (b->wth.value < 0)
            b->wth.state = -1;
}

void    get_zero(pf *a,t_flags *b, va_list *ap)
{
    int  i;
    
    if (*a->buff == '0')
    {
        b->zero.state = 1;
        b->min.value = 1;
        a->buff++;
        while (*a->buff == ' ')
            a->buff++;
        if (*a->buff == '*')
            b->zero.value = va_arg(*ap, int);
        else if (*a->buff == '.')
            get_prec(a, b, ap);
        if (ft_isdigit(*a->buff) == 1)
        {
            b->zero.value = ft_atoi(a->buff);
            i = count_int(b->zero.value);
            while (i != 1)
            {
                a->buff++;
                i--;
            }
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
    }
    if (b->zero.value == 0)
        b->prec.state = 1;
}

void    get_prec(pf *a, t_flags *b, va_list *ap)
{
    int i;
    
    if (*a->buff == '.')
    {
        b->prec.state = 1;
        a->buff++;
        if (*a->buff == '*')
            b->prec.value = va_arg(*ap, int);
        else if (ft_isdigit(*a->buff) == 1)
        {
            b->prec.value = ft_atoi(a->buff);
            i = count_int(b->prec.value);
            while (i != 1)
            {
                a->buff++;
                i--;
            }
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
    }
    if (b->zero.state == 1)
    {
        b->check.state = b->zero.value;
        b->wth.value = b->zero.value;
        b->wth.state = 1;
    }

    if (b->wth.value < b->prec.value)
        b->zero.value = b->prec.value;
}