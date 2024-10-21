/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:29:36 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/21 19:21:30 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	char	result;
	int		counter;

	counter = 0;
	result = 0;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	result = (nbr % 10) + '0';
	write(1, &result, 1);
	counter++;
	return (counter);
}
