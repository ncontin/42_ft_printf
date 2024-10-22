/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:52:31 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/22 20:12:36 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *format, va_list args, int *i)
{
	int	counter;
	int	ptr;

	counter = 0;
	if (format[*i] == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (format[*i] == '%')
	{
		write(1, "%", 1);
		counter++;
	}
	else if (format[*i] == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (format[*i] == 'u')
		counter += ft_putnbr_uns(va_arg(args, int));
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
	va_end(args);
	return (counter);
}

int	main(void)
{
	int	res;
	int	res2;

	res = printf("%s %d %c %% %u", "Jeff", 123, 'J', 123);
	printf("\n");
	printf("printf return: %d\n", res);
	res2 = ft_printf("%s %d %c %% %u", "Jeff", 123, 'J', 123);
	printf("\n");
	printf("ft_printf return: %d\n", res2);
}
