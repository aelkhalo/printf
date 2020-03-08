/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:58:34 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/03/08 20:15:42 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_hex(unsigned long n, t_flags *b)
{
	int i;

	i = 0;
	if (!n && !b->prec.s)
		i++;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i + (!n ? 0 : 1));
}

void	ft_puthex(unsigned long n, int maj)
{
	char	number[20];
	int		i;

	i = 0;
	if (n == 0)
		number[i++] = '0';
	while (n >= 10)
	{
		if (n % 16 > 9)
			number[i] = n % 16 - 10 + (maj == 1 ? 'A' : 'a');
		else
			number[i] = n % 16 + '0';
		i++;
		n = n / 16;
	}
	if (n > 0 && n < 10)
	{
		number[i] = n % 16 + '0';
		i++;
	}
	number[i] = '\0';
	i--;
	while (i >= 0)
		write(1, &number[i--], 1);
}
