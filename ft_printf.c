/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:46:56 by krwongwa          #+#    #+#             */
/*   Updated: 2023/10/12 13:36:51 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char str,va_list arg_ptr)
{
	if (str == 'c')
		return (ft_putchar(va_arg(arg_ptr, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(arg_ptr, char *)));
	else if (str == 'p')
		return (ft_print_add(va_arg(arg_ptr, unsigned long)));
	else if (str == 'd' || str == 'i')
		return (ft_itoa(va_arg(arg_ptr, int),10,0));
	else if (str == 'u')
		return (ft_itoa(va_arg(arg_ptr, unsigned int),10,0));
	else if (str == 'x')
		return (ft_itoa(va_arg(arg_ptr, unsigned int),16 ,0));
	else if (str == 'X')
		return (ft_itoa(va_arg(arg_ptr, unsigned int),16 ,1));
	else if (str == '%')
		return (ft_putchar('%'));
	return (-1);
}

int ft_printf(const char *str, ...)
{
	va_list arg_ptr;
	size_t i;
	size_t count;

	count = 0;
	va_start(arg_ptr,str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += check(str[++i],arg_ptr);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg_ptr);
	return (count);
}

/*
int main()
{
	printf("%d\n",ft_printf("%s\n",NULL));
	printf("%d\n",printf("%s\n",NULL));
}
*/
