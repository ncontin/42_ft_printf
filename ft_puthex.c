/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:56:56 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 18:13:44 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char hex_case)
{
	int	counter;
	int	rem;

	counter = 0;
	if (n >= 16)
		counter += ft_puthex(n / 16, hex_case);
	rem = (n % 16);
	if (rem < 10)
		ft_putchar(rem + '0');
	else
	{
		if (hex_case == 'X')
			ft_putchar(rem + 55);
		else if (hex_case == 'x')
			ft_putchar(rem + 87);
	}
	counter++;
	return (counter);
}
