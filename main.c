/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:39:23 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/02/28 08:35:42 by elkhaluffy       ###   ########.fr       */
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
    //s = ft_printf("|%.4s|", j);
    r = printf("|%.0d|", 0);
    printf("\n");
    s = ft_printf("|%.0d|", 0);
    printf("\n");
    // r = printf("%3d\n", 100);
    // s = ft_printf("%3d\n", 100);
    printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
    // r = printf("a%3da\n", 100);
	// s = ft_printf("a%3da\n", 100);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
    // r = printf("%4d\n", 100);
	// s = ft_printf("%4d\n", 100);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
    // r = printf("%2d\n", -100);
	// s = ft_printf("%2d\n", -100);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
    // r = printf("%3d\n", -100);
	// s = ft_printf("%3d\n", -100);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
	// r = printf("%4d\n", -100);
	// s = ft_printf("%4d\n", -100);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
	// r = printf("%4d\n", 0);
	// s = ft_printf("%4d\n", 0);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
	// r = printf("%1d\n", 0);
	// s = ft_printf("%1d\n", 0);
    // printf("\n%d\n%d\n", r, s);
    // printf("-----------------------\n");
	// r = printf("a%1da\n", 0);
	// s = ft_printf("a%1da\n", 0);
    // printf("\n%d\n%d\n", r, s);
    return 0;
}


// todo treat no number in precesion while there is a point
// trea the case when a nuber is < 0 and precesion is > 1
// if 0 and prece then !(0)
// if is dot == 1 then list prece == 0
// if list prece 0 and minw then ' ' else no prece and no minw then nothing