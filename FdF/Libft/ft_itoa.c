/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:24:43 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/07 19:34:16 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_completeitoa(int n, size_t end, char *ptr)
{
	char	a;

	ptr[end--] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		a = (n % 10) + '0';
		ptr[end] = a;
		n = (n / 10);
		end--;
	}
}

char	*ft_itoa(int n)
{
	int		aux;
	size_t	isize;
	char	*ptr;

	aux = n;
	isize = 1;
	while (aux > 9 || aux < -9)
	{
		aux = aux / 10;
		isize++;
	}
	if (n < 0)
		isize++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ptr = malloc(sizeof(char) * (isize + 1));
	if (!ptr)
		return (NULL);
	ft_completeitoa(n, isize, ptr);
	return (ptr);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *str;

	str = ft_itoa(INT_MIN);
	printf("%s\n", str);
	free(str);
	system("leaks a.out");

	str = ft_itoa(0);
	printf("%s\n", str);
	free(str);

	system("leaks a.out");

	return (0);
}

Preguntar por qué

str = "-2147483648" en linea 53
str = "0" en linea 55
*/
