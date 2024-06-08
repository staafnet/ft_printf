/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:40:02 by rgrochow          #+#    #+#             */
/*   Updated: 2024/06/07 22:25:04 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char uppercase)
{
	int		count;
	char	*hex;

	count = 0;
	if (uppercase == 'u')
	{
		if (n >= 10)
			count += ft_putunbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else if (uppercase == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
