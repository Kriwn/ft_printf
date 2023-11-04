/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:06:52 by krwongwa          #+#    #+#             */
/*   Updated: 2023/10/11 14:06:52 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countunlong(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	address(unsigned long n, int base, int flag)
{
	int		count;
	int		i;
	char	*str;

	count = countunlong(n, base);
	i = 0;
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (-1);
	str[count] = '\0';
	while (count--)
	{
		str[count] = allbase((n % base), base, flag);
		n /= base;
	}
	i += ft_putstr(str);
	free(str);
	return (i);
}

int	ft_print_add(unsigned long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += address(n, 16, 0);
	return (count);
}
