/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:39:23 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/08 20:33:20 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int r = 0;
    int s = 0;
    //char *j = NULL;
    // printf("n |%*c| plays %*c\n", 4, s, 4, r);
    // ft_printf("n |%*c| plays %*c\n", 4,s, 4, r);
    // printf("===================================================================================================\n");
    s = ft_printf("|%x|\n", -16);
    r =    printf("|%x|\n", -16);
    printf("\n%d\n%d\n\n", s, r);
  
    // r =    printf("|%*.*d|\n", -10, -10, -10);
    // s = ft_printf("|%*.*d|\n", -10, -10, -10);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%-.d|\n", 10);
    // r =    printf("|%-.d|\n", 10);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%*.*d|\n",10, 9, 0);
    // r =    printf("|%*.*d|\n",10, 9, 0);
    // printf("\n%d\n%d\n\n", s, r);
    // s = ft_printf("|%.4d|\n", 34231432);
    // r =    printf("|%.4d|\n", 34231432);
    // printf("\n%d\n%d\n\n", s, r);
    
    // s = ft_printf("|%0*.*d|\n", 5, 3, 1);
    // r =    printf("|%0*.*d|\n", 5, 3, 1);
    // printf("\n%d\n%d\n\n", s, r);
    return 0;
}