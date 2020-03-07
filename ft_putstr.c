/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:24:56 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/07 06:22:06 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c);

void	ft_putstr(char *str , int val , pf *a)
{
	int i;

	i = 0;
	while (val != 0)
	{
		ft_putchar(str[i]);
		i++;
		val--;
		a->lenght++;
		if (val < 0)
			break ;
	}
}
