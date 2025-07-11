/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:18:44 by manuemar          #+#    #+#             */
/*   Updated: 2023/11/02 18:46:38 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_heigth(t_map *map, char *str)
{
	char	*file_line;
	int	fd;

	map->heigth = 0;
	fd = open(str, O_RDONLY);
	file_line = get_next_line(fd);
	while (file_line)
	{
		map->heigth++;
		free(file_line);
		file_line = get_next_line(fd);
	}
	close(fd);
}

void	read_map(t_map *map, char *str)
{
	int	fd;
	char *file_line;
	size_t	j;

	count_heigth(map, str);
	map->map = malloc(sizeof(int **) * (map->heigth));
}
