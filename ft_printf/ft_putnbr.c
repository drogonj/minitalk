/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:42:03 by ngalzand          #+#    #+#             */
/*   Updated: 2022/11/15 12:47:41 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, size_t len)
{
	unsigned int	un;
	int				lentmp;

	lentmp = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		un = -n;
		len++;
	}
	else
		un = n;
	while (un > 9)
	{
		lentmp = ft_putnbr(un / 10, len);
		if (lentmp == -1)
			return (-1);
		len = lentmp;
		un %= 10;
	}
	if (ft_putchar(un + '0') == -1)
		return (-1);
	return (++len);
}

int	ft_putunsignednbr(unsigned int n, size_t len)
{
	int	lentmp;

	lentmp = 0;
	while (n > 9)
	{
		lentmp = ft_putnbr(n / 10, len);
		if (lentmp == -1)
			return (-1);
		len = lentmp;
		n %= 10;
	}
	if (ft_putchar(n + '0') == -1)
		return (-1);
	return (++len);
}
