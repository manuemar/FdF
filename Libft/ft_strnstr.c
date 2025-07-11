/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:34:10 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/07 18:20:10 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	j = 0;
	while (*haystack)
	{
		i = 0;
		if (*haystack == *needle && needle[i] != 0)
		{
			while (haystack[i] == needle[i] && needle[i] && (i + j) < len)
			{
				if (needle[i + 1] == 0)
					return ((char *)haystack);
				i++;
			}
		}
		haystack++;
		j++;
	}
	return (0);
}
