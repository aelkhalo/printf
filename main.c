/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:39:23 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/02/29 12:07:43 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int r = 0;
    int s = 0;
    //char *j = "hello";
    // printf("n |%*c| plays %*c\n", 4, s, 4, r);
    // ft_printf("n |%*c| plays %*c\n", 4,s, 4, r);
    // printf("===================================================================================================\n");
    // r = printf("|%.4s|", j);
    // printf("\n");
    // s = ft_printf("|%.4s|", j);
  
  
    // r =    printf("|%*.*d|\n", -10, -10, -10);
    // s = ft_printf("|%*.*d|\n", -10, -10, -10);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%-.d|\n", 10);
    // r =    printf("|%-.d|\n", 10);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%*.*d|\n",10, 9, 0);
    // r =    printf("|%*.*d|\n",10, 9, 0);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%0.4d|\n", 0);
    // r =    printf("|%0.4d|\n", 0);
    // printf("\n%d\n%d\n\n", s, r);
    
    s = ft_printf("|%s|\n", "");
    r =    printf("|%s|\n", "");
    printf("\n%d\n%d\n", s, r);

    
    
    return 0;
}

// print_test(".*d"); print_ret(PRINTF_MACRO("Bla bla %.*d", 0, 123));
// print_test(".*d"); print_ret(PRINTF_MACRO("Bla bla %.*d", 3, 123));
// print_test(".*d"); print_ret(PRINTF_MACRO("Bla bla %.*d", 10, 123));
// print_test(".*d"); print_ret(PRINTF_MACRO("Bla bla %.*d", -15, 123));
// print_test("-d"); print_ret(PRINTF_MACRO("Bla bla %-d", 12345678));