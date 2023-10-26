/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:50:25 by manuemar          #+#    #+#             */
/*   Updated: 2023/10/09 22:06:34 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *rest, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(rest, buffer);
	if (!aux)
		return (free(buffer), free(rest), NULL);
	free(rest);
	return (aux);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_return_line(char **bufferptr)
{
	int		i;
	char	*line;
	char	*buffer;

	buffer = *bufferptr;
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(buffer), *bufferptr = NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_file_reader(int fd, char *rest)
{
	char	*buffer;
	int		byte_read;

	if (!rest)
		rest = ft_calloc(1, 1);
	if (!rest)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(rest), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(rest), NULL);
		buffer[byte_read] = 0;
		rest = ft_free(rest, buffer);
		if (!rest)
			return (free(rest), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (rest);
}

//El único cambio es añadir entre corchetes el fd que le mandas
char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
			(free(buffer[fd]), buffer[fd] = NULL);
		return (NULL);
	}
	buffer[fd] = ft_file_reader(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_return_line(&buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
