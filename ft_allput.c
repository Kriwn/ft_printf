/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:47:14 by krwongwa          #+#    #+#             */
/*   Updated: 2023/10/07 00:47:14 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_putchar(char c)
{
	c = (unsigned char)c;
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	else
		return (write(1, s, ft_strlen(s)));
}
