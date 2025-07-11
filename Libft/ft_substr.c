/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:19:42 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/09 02:07:26 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	size_t	j;
	char	*str;

	slen = ft_strlen(s);
	if (start <= slen)
	{
		if (len + start > slen)
			len = slen - start;
		str = malloc(((len) + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		i = start;
		j = 0;
		while (j < len && len + start <= slen)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}
