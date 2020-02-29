/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:15:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/02/29 04:21:46 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        c_handler(pf *a, t_flags *b, va_list *ap)
{
    int val;
    int i;
    
    i = va_arg(*ap, int);
    val = 1;
    if (b->wth.value < 0){
        b->wth.state = -1;
        b->wth.value *= -1;
    }
    if (b->wth.state == 1)
        print_spaces(&(*a), &(*b), val);
    ft_putchar(i);
    if(b->wth.state == -1)
        print_spaces(&(*a), &(*b), val);
}

void        d_handler(pf *a, t_flags *b, va_list *ap)
{
    int val;
    int yes;
    int i;
    
    yes = 0;
    val = 0;
    i = va_arg(*ap, int);
    if (i < 0 && (yes += 1 || 1))
    {
        i *= -1;
        if (b->wth.value > 0)
            b->wth.value -= 1;
        else
            b->wth.value += 1;
        if (b->zero.state)
            b->zero.value -= 1;
        a->lenght += 1;
    }
    if (b->prec.value < 0)
        b->prec.state = 0;
    if (b->zero.state == 1 && b->prec.state == 1)
    {
        b->zero.state = 0;
        b->wth.state = 1;
        b->wth.value = b->zero.value;
    }
    val = count_int(i);
    if (b->prec.state && b->wth.value > b->prec.value && b->prec.value > 1 && b->wth.state == 1)
        b->wth.value += val;
    else if (b->prec.state && b->wth.value > b->prec.value && b->wth.state == 1)
        b->wth.value += val;
    if (val > b->prec.value && b->prec.value > 0 && b->wth.value == b->prec.value)
        b->wth.value = 0;
    if (b->prec.value > b->wth.value && b->wth.value > 0)
        b->wth.value = 0;
    if (b->wth.state == 1 && b->wth.value > b->prec.value && b->prec.value > val && b->prec.state)
        b->wth.value  -= b->prec.value;
    if (b->wth.value > b->prec.value && b->prec.value < val && b->prec.state)
        b->wth.value -= val;
    if (b->wth.value < 0){
        b->wth.state = -1;
        b->wth.value *= -1;
    }
    if (b->wth.state == 1)
    {
        print_spaces(&(*a), &(*b), val);
        b->zero.value = b->prec.value;
    }
    if (yes)
        ft_putchar('-');
    if  (b->prec.state == 1 && b->prec.value > val)
        print_zeros(&(*a), &(*b), val);
    if (b->zero.state == 1 && b->zero.value > val)
        print_zeros(&(*a), &(*b), val);
    if (b->prec.value == 0 && i == 0 && b->zero.state == 0 && b->wth.state == 0 && b->prec.state)
        a->lenght--;
    else if (b->wth.state == 2)
    {
        if (i == 0)
            a->lenght--;
        else
            ft_putnbr(i);
    }
    else if (b->prec.value == 0 && b->prec.state == 1 && i == 0 && (b->wth.state == -1 || b->wth.state == 1 || b->wth.state == 0))
        ft_putchar(' ');
    else
        ft_putnbr(i);
    if (b->wth.state == -1 && b->prec.state == 1 && b->prec.value > val)
        b->wth.value -= b->prec.value - val ;
    else if (b->wth.state == -1 && b->prec.value == 1 && b->prec.state)
        b->wth.value = b->wth.value;
    else if (b->wth.state == -1 && b->prec.value < val && b->prec.state)
        b->wth.value += val;
    if (b->wth.state == -1)
        print_spaces(&(*a), &(*b), val);
    while (val != 1)
    {
        a->lenght++;
        val--;
    }
}

void        print_zeros(pf *a, t_flags *b, int val)
{
    b->zero.value -= val;
    while (b->zero.value != 0)
    {
        ft_putchar('0');
        b->zero.value--;
        a->lenght++;
        if (b->zero.value < 0)
            break ;
    }
}

void        print_spaces(pf *a, t_flags *b, int val)
{   if (b->wth.value >= val)
   {
       while ((b->wth.value - val) != 0)
           {
                ft_putchar(' ');
                b->wth.value--;
                a->lenght++;
                if (b->wth.value < 0)
                    break ;
           }
   }
}

void        f_handler(pf *a, t_flags *b, va_list *ap)
{
    // char    *s;
    if (*(a->buff) == 'd' || *(a->buff) == 'i' || *(a->buff) == 'u')
        d_handler(&(*a), &(*b), ap);
    
    else if (*(a->buff) == 'c')
        c_handler(&(*a), &(*b), ap);
    
    // else if (*(a->buff) == 's')
    // {
    //     s = va_arg(*ap, char*);
    //     ft_putstr(s);
    // }
    // else if (*(a->buff) == '%')
    // {
    //     ft_putchar('%');
    // }
    // else if (*(a->buff) == 'p')
    // {
    //     s = va_arg(*ap, char*);
    // }
}