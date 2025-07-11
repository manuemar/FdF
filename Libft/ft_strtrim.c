/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:38 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/28 23:09:30 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_comptoset(const char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	size_t	i;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1);
	if (s1)
	{
		while (ft_comptoset(s1[start], set) == 1)
			start++;
		while (end > start && end > 0 && ft_comptoset(s1[end - 1], set) == 1)
			end--;
	}
	size = end - start;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size))
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
