/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:05:54 by rgrochow          #+#    #+#             */
/*   Updated: 2024/06/08 06:46:28 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int parse_format(char fmt, void *args)
{
	int count;

	count = 0;
	if (fmt == 'c')
		count += ft_putchar((int *)args);
	else if (fmt == 's')
		count += ft_putstr((char *)args);
	else if (fmt == 'p')
		count += ft_putptr((unsigned long long)args);
	else if (fmt == 'd' || fmt == 'i')
		count += ft_putnbr((size_t)args);
	else if (fmt == 'u')
		count += ft_putunbr((unsigned int)(uintptr_t)args);
	else if (fmt == 'x' || fmt == 'X')
		count += ft_puthex((unsigned int)(uintptr_t)args, fmt);
	else if (fmt == '%')
		count += write(1, &fmt, 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += parse_format(*format, va_arg(args, void *));
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
