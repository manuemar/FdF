/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:36:32 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/02 12:41:26 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		b;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 10 && n >= 0)
	{
		a = (n % 10) + '0';
		write(fd, &a, 1);
	}
	else if (n >= 0)
	{
		b = (n / 10);
		ft_putnbr_fd(b, fd);
		a = (n % 10) + '0';
		write(fd, &a, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		b = n * (-1);
		ft_putnbr_fd(b, fd);
	}
}
