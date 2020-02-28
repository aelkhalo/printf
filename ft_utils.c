/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 00:52:27 by elkhaluffy        #+#    #+#             */
/*   Updated: 2020/02/22 03:11:31 by elkhaluffy       ###   ########.fr       */
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