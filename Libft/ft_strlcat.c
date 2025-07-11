/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:37:22 by manuemar          #+#    #+#             */
/*   Updated: 2023/04/12 18:23:00 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlength;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	dstlength = i;
	if (dstlength > dstsize)
		dstlength = dstsize;
	while (src[j] && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dstlength + ft_strlen(src));
}
/*
int main(void)
{
	char	dst[20] = "hola mundo ";
	char	src[] = "patatapatatapatatapatatapatatapatatapatata";

	printf("%zu\n", ft_strlcat(dst, src, 20));
	printf("%s\n", dst);
	return (0);
}

*/
