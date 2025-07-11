/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:21:15 by manuemar          #+#    #+#             */
/*   Updated: 2023/01/24 20:07:30 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <limits.h>
#include <string.h>
#include <string.h>

int	main(void)
{
	char *str = malloc((long)((long)INT_MAX + 2));

	if (!str)
		return (1);
	bzero(str, (long)((long)INT_MAX + 2));
	memset(str, '*', (long)((long)INT_MAX + 1));
	ft_strlen(str);
	free(str);
	system("leaks a.out");
	return (123);
}*/
