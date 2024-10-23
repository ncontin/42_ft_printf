/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noscrub <noscrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:47:24 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 16:30:56 by noscrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *n)
{
	int	counter;

	counter = 2;
	write(1, "0x", 2);
	counter += ft_puthex((unsigned long long int)n, 'x');
	return (counter);
}
