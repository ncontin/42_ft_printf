/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noscrub <noscrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:40:05 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 15:57:28 by noscrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnbr_uns(n / 10);
	ft_putchar((n % 10) + '0');
	counter++;
	return (counter);
}
