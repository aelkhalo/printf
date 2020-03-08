/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 02:40:20 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/08 17:27:59 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_u_putnbr(unsigned int nb)
{
	unsigned int n;

	// if (nb < 0)
	// {
	// 	ft_putchar('-');
	// 	n = -nb;
	// }
	// else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}