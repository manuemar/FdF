/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:52:52 by manuemar          #+#    #+#             */
/*   Updated: 2023/01/19 21:24:14 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dst;
	if (!dst && !src)
		return (0);
	if (s1 < s2 && s2 < s1 + len)
	{
		i = len;
		while (i-- > 0)
			s2[i] = s1[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (s2);
}
