/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:13:48 by manuemar          #+#    #+#             */
/*   Updated: 2023/02/12 19:43:10 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

int	ft_checkadd(const char *s, size_t i, size_t wordlen)
{
	if (s[i + wordlen] != '\0')
		i = wordlen + i + 1;
	else
		i = wordlen + i;
	return (i);
}

char	**ft_freeall(char **ptr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

size_t	ft_lenword(const char *s, char c, size_t i)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen + i] != c && s[wordlen + i] != '\0')
		wordlen++;
	return (wordlen);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	wordcount;
	size_t	wordlen;

	ptr = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	wordcount = 0;
	while (s[i])
	{
		wordlen = ft_lenword(s, c, i);
		if (s[i] != c)
		{
			ptr[wordcount] = ft_substr(s, i, wordlen);
			if (!ptr[wordcount])
				return (ft_freeall(ptr, wordcount));
			wordcount++;
		}
		i = ft_checkadd(s, i, wordlen);
	}
	ptr[wordcount] = NULL;
	return (ptr);
}
/*

int main(void)
{
	char	**result;
	size_t	i;

	i = 0;
	result = ft_split("Hola mundo    patata", ' ');
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return (0);
}

*/
//Function count words
//Function count words size
//Function ft free on error on malloc words
//Function substr
