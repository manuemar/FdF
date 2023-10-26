/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:16:00 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/02 03:36:32 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	strsize;
	size_t	i;

	strsize = ft_strlen(s1);
	ptr = malloc((sizeof(char) * strsize) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < strsize)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
