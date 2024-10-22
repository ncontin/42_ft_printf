/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:52:31 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/22 12:59:33 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *format, va_list args, int *i)
{
	int	counter;

	counter = 0;
	if (format[*i] == 's')
	{
		counter += ft_putstr(va_arg(args, char *));
	}
	else if (format[*i] == 'd')
	{
		counter += ft_putnbr(va_arg(args, int));
	}
	(*i)++;
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		i;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += handle_format(format, args, &i);
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
			i++;
		}
	}
	// while (format[i] != '%' && format[i])
	// {
	// 	write(1, &format[i], 1);
	// 	i++;
	// 	counter++;
	// }
	// if (format[++i] == 's')
	// {
	// 	counter += ft_putstr(va_arg(args, char *));
	// 	i++;
	// 	counter++;
	// }
	// while (format[i] != '%' && format[i])
	// {
	// 	write(1, &format[i++], 1);
	// 	counter++;
	// }
	// if (format[++i] == 'd')
	// {
	// 	counter += ft_putnbr(va_arg(args, int));
	// 	i++;
	// }
	// while (format[i])
	// {
	// 	write(1, &format[i], 1);
	// 	i++;
	// }
	va_end(args);
	return (counter);
}

int	main(void)
{
	int	result;
	int	result2;

	result = printf("Hello my name is %s and I am %d", "Jeff", 34);
	printf("\n");
	printf("printf return: %d\n", result);
	result2 = ft_printf("Hello my name is %s and I am %d", "Jeff", 34);
	printf("\n");
	printf("ft_printf return: %d\n", result2);
}
