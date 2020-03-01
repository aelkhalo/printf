/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:50:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/01 09:14:13 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    get_flags(pf *a, t_flags *b, va_list *ap)
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
            else if (*a->buff == '-' || *a->buff == '*' || ft_isdigit(*a->buff) == 1)
                get_wth(a, b, ap);
            if (*a->buff == '.')
                get_prec(a, b, ap);
            a->buff++;
        }

}

void    get_wth(pf *a, t_flags *b, va_list *ap)
{
    int i; 
    
    if (*a->buff == '-' || *a->buff == '*' || ft_isdigit(*a->buff) == 1)
    {
        b->wth.state = 1;
        if (*a->buff == '*')
            b->wth.value = va_arg(*ap, int);
        else if (*a->buff == '-')
        {
            b->wth.state = -1;
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
            else if (*a->buff == '.')
                b->wth.state = 2;
        }
        else if (ft_isdigit(*a->buff) == 1)
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
    if (b->wth.value < 0)
            b->wth.state = -1;
}

void    get_zero(pf *a,t_flags *b, va_list *ap)
{
    int i;
    
    if (*a->buff == '0')
    {
        b->zero.state = 1;
        a->buff++;
        while (*a->buff == ' ')
            a->buff++;
        if (*a->buff == '*')
            b->zero.value = va_arg(*ap, int);
        else if (*a->buff == '.')
            a->buff++;
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
            if (b->prec.value == 0 && b->wth.state == 0)
                b->wth.state = 2;
        }
        else if (ft_isalpha(*a->buff))
            a->buff--;
    }
    if (b->zero.state)
        b->wth.value = b->zero.value;
    else
        b->zero.value = b->prec.value;
    
}
void    get_in(t_flags *b)
{
    b->wth.state = 0;
    b->wth.value = 0;
    b->zero.state = 0;
    b->zero.value = 0;
    b->prec.state = 0;
    b->prec.value = 0;
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    pf      a;
    t_flags b;
    
    va_start(ap, str);
    a.buff = (char *) str;
    a.lenght = 0;
    while (*a.buff)
    {
        if (*a.buff == '%')
        {
            a.buff++;
            get_in(&b);
            get_flags(&a, &b, &ap);
            f_handler(&a, &b, &ap);
            a.flags++;
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