/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:29:36 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 18:13:41 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		counter++;
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	counter++;
	return (counter);
}
