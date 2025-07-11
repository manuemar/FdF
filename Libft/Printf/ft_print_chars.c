/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:23:56 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/31 19:41:41 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//%c y %% || imprimir chars
int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

//%s || imprimir strings
int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

//%p || imprimir punteros
int	ft_print_hexal_pointer(unsigned long long n, int cont)
{
	int	x;

	if (n < 16)
	{
		x = dtohl(n % 16);
		write(1, &x, 1);
		return (cont);
	}
	else if (n > 15)
	{
		cont += ft_print_hexal_pointer(n / 16, cont);
		x = dtohl(n % 16);
		write(1, &x, 1);
	}
	return (cont);
}

int	ft_print_pointer(unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	return (2 + ft_print_hexal_pointer(ptr, 1));
}
