/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:38:56 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/31 18:18:01 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x y %X || imprimir numeros hexadecimales en mayusculas y minusculas
int	dtohu(int n)
{
	if (10 > n && n >= 0)
		return (n + '0');
	else if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	return (0);
}

int	dtohl(int n)
{
	if (10 > n && n >= 0)
		return (n + '0');
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return (0);
}

int	ft_print_hexau(unsigned int n, int cont)
{
	int	x;

	if (n < 16)
	{
		x = dtohu(n % 16);
		write(1, &x, 1);
		return (cont);
	}
	else if (n > 15)
	{
		cont += ft_print_hexau(n / 16, cont);
		x = dtohu(n % 16);
		write(1, &x, 1);
	}
	return (cont);
}

int	ft_print_hexal(unsigned int n, int cont)
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
		cont += ft_print_hexal(n / 16, cont);
		x = dtohl(n % 16);
		write(1, &x, 1);
	}
	return (cont);
}
