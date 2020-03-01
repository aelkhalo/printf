/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 00:52:27 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/01 08:39:06 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_int(unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	if (n <= 9)
		i++;
	return (i);
}

// void        d_handler(pf *a, t_flags *b, va_list *ap)
// {
//     int val;
//     int yes;
//     int i;
    
//     yes = 0;
//     val = 0;
//     i = va_arg(*ap, int);
//     if (i < 0 && (yes += 1 || 1))
//     {
//         i *= -1;
//         if (b->wth.value > 0)
//             b->wth.value -= 1;
//         else
//             b->wth.value += 1;
//         if (b->zero.state)
//             b->zero.value -= 1;
//         a->lenght += 1;
//         if (i < 0)
//             yes = 0;
//     }
//     if (b->prec.value < 0)
//         b->prec.state = 0;
//     if (b->zero.state == 1 && b->prec.state == 1)
//     {
//         b->zero.state = 0;
//         b->wth.state = 1;
//         b->wth.value = b->zero.value;
//     }
//     val = count_int(i);
//     if (b->wth.value < 0 && b->prec.value < val)
//         b->prec.value = 0;
//      if (b->prec.state && b->wth.value > b->prec.value && b->prec.value > 1 && b->wth.state == 1 && b->prec.value != val)
//         b->wth.value += val;
//     else if (b->prec.state && b->wth.value > b->prec.value && b->wth.state == 1 && b->prec.value != val)
//         b->wth.value += val;
    
//     if (val > b->prec.value && b->prec.value > 0 && b->wth.value == b->prec.value)
//         b->wth.value = 0;
//     else if (b->prec.value > b->wth.value && b->wth.value > 0)
//         b->wth.value = 0;
    
//     if (b->wth.state && b->wth.value >= b->prec.value && b->prec.value > val && b->prec.state)
//         b->wth.value  -= b->prec.value;
//     else if (b->wth.value > b->prec.value && b->prec.value < val && b->prec.state && b->wth.state)
//         b->wth.value -= val;
    
//     if (b->wth.value < 0){
//         b->wth.state = -1;
//         b->wth.value *= -1;
//     }
    
//     if (b->wth.state == 1)
//     {
//         print_spaces(&(*a), &(*b), val);
//         b->zero.value = b->prec.value;
//     }
// }