/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:20:17 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/31 18:17:03 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%d y %i || imprimir numeros enteros en base 10
int	ft_print_int(int n, int cont)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		cont = 11;
	}
	else if (n < 10 && n >= 0)
	{
		a = (n % 10) + '0';
		write(1, &a, 1);
		return (cont);
	}
	else if (n >= 10)
	{
		cont += ft_print_int(n / 10, cont);
		a = (n % 10) + '0';
		write(1, &a, 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		cont += ft_print_int(n * (-1), cont);
	}
	return (cont);
}

//%u || imprimir numeros enteros positivos en base 10
int	ft_print_pos(unsigned int n, int cont)
{
	char	a;

	if (n < 10)
	{
		a = (n % 10) + '0';
		write(1, &a, 1);
		return (cont);
	}
	else if (n >= 10)
	{
		cont += ft_print_int(n / 10, cont);
		a = (n % 10) + '0';
		write(1, &a, 1);
	}
	return (cont);
}
