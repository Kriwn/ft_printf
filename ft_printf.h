/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:26:41 by krwongwa          #+#    #+#             */
/*   Updated: 2023/09/26 15:26:41 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __linux__
#  define PTR_NULL "(nil)"
# else
#  define PTR_NULL "0x0"
# endif

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *str, ...)
			__attribute__ (( format( printf, 1, 2 ) ));
int			check(const char str, va_list *arg_ptr);
int			ft_putstr(char *s);
int			ft_putchar(char c);
size_t		ft_strlen(const char *s);
int			ft_print_add(unsigned long n);
long int	ft_ltoa(long int n, int base, int flag);
char		allbase(int i, int base, int flag);

#endif
