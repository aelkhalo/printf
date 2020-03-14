/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:46:56 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 01:49:08 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_hex(unsigned long n, int b)
{
	int i;

	i = 0;
	if (!n && b)
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

void	ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	while (i < n)
		write(1, &s[i++], 1);
}

void	cal_lenght(t_pf *a, int val)
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
