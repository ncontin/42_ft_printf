/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:52:31 by ncontin           #+#    #+#             */
/*   Updated: 2024/10/23 18:13:49 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(const char *format, va_list args, int *i)
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
	else if (format[*i] == 'x' || format[*i] == 'X')
		counter += ft_puthex(va_arg(args, int), format[*i]);
	else if (format[*i] == 'p')
		counter += ft_putptr(va_arg(args, void *));
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

// int	main(void)
// {
// 	int		*ptr;
// 	int		out_OG;
// 	int		out_FT;
// 	char	*dummy;

// 	int s, d, i, c, perc, u, x, xu, p;
// 	int sf, df, ift, cf, percf, uf, xf, xuf, pf;
// 	ptr = &s;
// 	s = printf("og s: %s", "Jeff");
// 	printf("\n");
// 	sf = ft_printf("ft s: %s", "Jeff");
// 	printf("\n");
// 	printf("%d || %d\n", s, sf);
// 	d = printf("og d: %d", 123);
// 	printf("\n");
// 	df = ft_printf("ft d: %d", 123);
// 	printf("\n");
// 	printf("%d || %d\n", d, df);
// 	i = printf("og i: %i", 123);
// 	printf("\n");
// 	ift = ft_printf("ft i: %i", 123);
// 	printf("\n");
// 	printf("%d || %d\n", i, ift);
// 	c = printf("og char: %c", '0');
// 	printf("\n");
// 	cf = ft_printf("ft char: %c", '0');
// 	printf("\n");
// 	printf("%d || %d\n", c, cf);
// 	perc = printf("og perc: %%");
// 	printf("\n");
// 	percf = ft_printf("ft perc: %%");
// 	printf("\n");
// 	printf("%d || %d\n", perc, percf);
// 	u = printf("og unsigned: %u", -1);
// 	printf("\n");
// 	uf = ft_printf("ft unsigned: %u", -1);
// 	printf("\n");
// 	printf("%d || %d\n", u, uf);
// 	x = printf("og hex: %x", 10);
// 	printf("\n");
// 	xf = ft_printf("ft hex: %x", 10);
// 	printf("\n");
// 	printf("%d || %d\n", x, xf);
// 	xu = printf("og hexup: %X", 10);
// 	printf("\n");
// 	xuf = ft_printf("ft hexup: %X", 10);
// 	printf("\n");
// 	printf("%d || %d\n", xu, xuf);
// 	p = printf("og ptr: %p", ptr);
// 	printf("\n");
// 	pf = ft_printf("ft ptr: %p", ptr);
// 	printf("\n");
// 	printf("%d || %d\n", p, pf);
// 	// printf(" %p %p ", 0, 0);
// 	// ft_printf(" %p %p ", 0, 0);
// 	dummy = NULL;
// 	out_OG = printf("OG -> This should be NULL: %s\n", dummy);
// 	out_FT = ft_printf("FT -> This should be NULL: %s\n", dummy);
// 	printf("OUTPUT OG = %d\n", out_OG);
// 	ft_printf("OUTPUT FT = %d\n", out_FT);
// 	out_OG = printf("OG -> 4294967293 in hexadecimal = %x\n", 4294967293u);
// 	out_FT = ft_printf("FT -> 4294967293 in hexadecimal = %x\n", 4294967293u);
// 	ft_printf("0 && 0--------------------\n");
// 	out_OG = printf("OG ->  %p %p \n", (void *)0, (void *)0);
// 	out_FT = ft_printf("FT ->  %p %p \n", (void *)0, (void *)0);
// 	printf("OUTPUT OG = %d\n", out_OG);
// 	ft_printf("OUTPUT FT = %d\n", out_FT);
// 	printf("francinette test %p %p \n", NULL, NULL);
// 	ft_printf("francinette test %p %p \n", NULL, NULL);
// 	return (0);
// }
