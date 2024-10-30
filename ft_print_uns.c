/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:40:05 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/30 10:55:21 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
		counter += ft_print_uns(n / 10);
	ft_print_char((n % 10) + '0');
	counter++;
	return (counter);
}
