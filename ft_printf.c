/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:52:31 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 13:06:25 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *format, va_list args, int *i)
{
	int	counter;

	counter = 0;
	if (format[*i] == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (format[*i] == '%')
	{
		ft_putchar('%');
		counter++;
	}
	else if (format[*i] == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (format[*i] == 'u')
		counter += ft_putnbr_uns(va_arg(args, int));
	else if (format[*i] == 'x')
		counter += ft_puthex(va_arg(args, int), 'x');
	else if (format[*i] == 'X')
		counter += ft_puthex(va_arg(args, int), 'X');
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
			ft_putchar(format[i]);
			counter++;
			i++;
		}
	}
	va_end(args);
	return (counter);
}

int	main(void)
{
	int	s;
	int	d;
	int	i;
	int	c;
	int	perc;
	int	u;
	int	x;
	int	xu;
	int	sf;
	int	df;
	int	ift;
	int	cf;
	int	percf;
	int	uf;
	int	xf;
	int	xuf;
	int	prtres;
	int	ft_prtres;

	// printf tests
	s = printf("printf string: %s", "Jeff");
	printf("\n");
	d = printf("printf d: %d", 123);
	printf("\n");
	i = printf("printf i: %i", 123);
	printf("\n");
	c = printf("printf char: %c", '0');
	printf("\n");
	perc = printf("printf perc: %%");
	printf("\n");
	u = printf("printf unsigned: %u", -1);
	printf("\n");
	x = printf("printf hex: %x", 10);
	printf("\n");
	xu = printf("printf hexup: %X", 10);
	printf("\n");
	// ft_printf tests
	sf = ft_printf("ft_pri string: %s", "Jeff");
	printf("\n");
	df = printf("ft_pri d: %d", 123);
	printf("\n");
	printf("ft_printf i: %i", 123);
	printf("\n");
	cf = ft_printf("ft_printf char: %c", '0');
	printf("\n");
	percf = ft_printf("ft_printf perc: %%");
	printf("\n");
	uf = ft_printf("ft_printf unsigned: %u", -1);
	printf("\n");
	xf = ft_printf("ft_printf hex: %x", 10);
	printf("\n");
	xuf = ft_printf("ft_printf hexup: %X", 10);
	printf("\n");
	// ft_prtres = sf + df + cf + percf + uf + xf + xuf;
	printf("ft res: %d", ft_prtres);
	printf("\n");
	// prtres = s + d + c + perc + u + x + xu;
	printf("og res: %d\n", prtres);
}
