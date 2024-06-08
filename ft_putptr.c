/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:38:02 by rgrochow          #+#    #+#             */
/*   Updated: 2024/06/07 23:49:30 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(unsigned long long ptr)
{
	int count;
	unsigned long long n;

	count = 0;
	n = (unsigned long long)ptr;
	count += ft_putstr("0x");
	if (n == 0)
		return (count + write(1, "0", 1));
	count += ft_puthex(n, 0);
	return (count);
}
