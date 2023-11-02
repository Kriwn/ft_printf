/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:27:43 by krwongwa          #+#    #+#             */
/*   Updated: 2023/09/08 11:27:43 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countlong(long int n, int base)
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

char	allbase(int i, int base, int flag)
{
	char	*s;

	if (flag && base == 16)
		s = "0123456789ABCDEF";
	else if (!flag && base == 16)
		s = "0123456789abcdef";
	else
		s = "0123456789";
	return (s[i]);
}

long int	ft_ltoa(long int n, int base, int flag)
{
	int		count;
	int		i;
	char	*str;

	i = 0;
	if (n < 0 && base == 10)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n < 0 && base == 16)
		n *= -1;
	count = countlong(n, base);
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
