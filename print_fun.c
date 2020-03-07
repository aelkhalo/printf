/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:23:01 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/07 18:33:58 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_zeros(pf *a, t_flags *b, int val)
{
    if (b->zero.v >= val)
    {
        b->zero.v -= val;
        while (b->zero.v != 0)
        {
            ft_putchar('0');
            b->zero.v--;
            a->lenght++;
            if (b->zero.v < 0)
                break ;
        }
    }
}

void    print_s_spaces(pf *a, t_flags *b)
{
    while (b->wth.v > 0)
    {
         ft_putchar(' ');
         b->wth.v--;
         a->lenght++;
         if (b->wth.v < 0)
             break ;
    }
    b->zero.v = b->prec.v;
}

void    print_spaces(pf *a, t_flags *b, int val)
{
    if (b->wth.v >= val)
    {
        b->wth.v -= val;
        while (b->wth.v != 0)
        {
             ft_putchar(' ');
             b->wth.v--;
             a->lenght++;
             if (b->wth.v < 0)
                 break ;
        }
        b->zero.v = b->prec.v;
    }
}
