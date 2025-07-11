/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:49:40 by manuemar          #+#    #+#             */
/*   Updated: 2023/11/02 18:31:44 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "fdf.h"

void	free_map(t_map map)
{

}

void	is_big_low(int num, t_map *map)
{
	if (!map->min_z && !map->max_z)
	{
		map->min_z = num;
		map->max_z = num;
	}
	if (num > map->max_z)
		map->max_z = num;
	if (num < map->min_z)
		map->min_z = num;
}

void	save_map(t_map *map, char *line, size_t j)
{
	size_t	i;
	int		num;
	char	**splitted_line;

	i = 0;
	map->width = 0;
	splitted_line = ft_split(line, ' ');
	while (splitted_line[map->width])
		map->width++;
	map->map[j] = malloc(sizeof(int *) * map->width);
	i = 0;
	while (splitted_line[i])
	{
		num = ft_atoi(splitted_line[i]);
		//meter gestion de errores (mapas no cuadrados o chars no numericos)
		map->map[j][i] = num;
		is_big_low(num, map);
		i++;
	}
}

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
	j = 0;
	fd = open(str, O_RDONLY);
	file_line = get_next_line(fd);
	while (file_line)
	{
		ft_printf("%s", file_line);
		save_map(map, file_line, j);
		j++;
		file_line = get_next_line(fd);
	}
}

*/

//Necesito calcular columnas (supongo que depende de la cantidad de veces que
//	reserve el split se puede tomar el valor de ahí, por lo que tengo que
//	modificarlo)

//Necesito recorrer todo el mapa una vez para sacar el valor máximo y mínimo
//	para añadir los colores

//Luego volver a leerlo para ya empezar a dibujar las lineas
