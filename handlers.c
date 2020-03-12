/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:15:19 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/12 22:37:53 by aelkhalo         ###   ########.fr       */
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

void	ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
		write(1, &s[i++], 1);
}

void    p_handler(pf *a, t_flags *b, va_list *ap)
{
    unsigned long long i;
    int val;
    int yes;
    int ex;
    
    i = va_arg(*ap, unsigned long long);
    yes = 0;
    ex = 0;
    if (b->wth.v < 0)
        b->wth.v *= -1;
    if (i == 0)
    {
        b->wth.v++;
        a->lenght--;
    }
    check_x_hand0(b, i);
    val = count_hex(i , 1) + (!i ? 1 : 0);
    val += 2;
    check_d_norme(a, b, val ,i);
    ft_putnstr("0x", 2);
    check_p_hand2(a, b, val, i);
    cal_lenght(a, val);
}

void    check_p_hand2(pf *a, t_flags *b, int val, unsigned long long i)
{
    int ex;
    
    ex = 0;
    check_x_hand3(a, b, val);
    if (b->zero.v == 0 && i == 0 && b->prec.v >= 0 && b->prec.s == 1)
    {
        if (b->wth.v > 0)
            b->wth.v++;
        ex = 1;
        a->lenght--;
    }
    if (ex == 0)
        ft_puthex(i, 0);
    if (b->wth.s == -1)
        print_spaces(&(*a), &(*b), val);
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

void    f_handler(pf *a, t_flags *b, va_list *ap)
{
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
    if (*(a->buff) == 'p')
        p_handler(&(*a), &(*b), ap);
}