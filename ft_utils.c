/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:46:13 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 01:48:34 by aelkhalo         ###   ########.fr       */
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

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int val, t_pf *a)
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
