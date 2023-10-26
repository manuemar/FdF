/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:00:36 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/31 19:01:05 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formats(va_list args, char const str)
{
	int	length_var;

	length_var = 0;
	if (str == 'c')
		length_var += ft_print_char(va_arg(args, int));
	else if (str == 's')
		length_var += ft_print_str(va_arg(args, char *));
	else if (str == 'p')
		length_var += ft_print_pointer(va_arg(args, unsigned long long));
	else if (str == 'd')
		length_var += ft_print_int(va_arg(args, int), 1);
	else if (str == 'i')
		length_var += ft_print_int(va_arg(args, int), 1);
	else if (str == 'u')
		length_var += ft_print_pos(va_arg(args, unsigned int), 1);
	else if (str == 'x')
		length_var += ft_print_hexal(va_arg(args, unsigned int), 1);
	else if (str == 'X')
		length_var += ft_print_hexau(va_arg(args, unsigned int), 1);
	else if (str == '%')
		length_var += ft_print_char('%');
	return (length_var);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	va_start(args, str);
	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += ft_print_formats(args, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			length++;
		}
		i++;
	}
	return (length);
	va_end(args);
}
/*
int	main(void)
{
	int x;

	x = 0;
	x = ft_printf("\001\002\007\v\010\f\r\n");
	printf("%d\n", x);
	ft_printf("%d", "hola");
	printf("%d\n", printf("%X\n", -321));
	ft_printf("%d\n", ft_printf("%X\n", -321));
	return (0);
}*/
