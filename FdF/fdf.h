/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:22 by manuemar          #+#    #+#             */
/*   Updated: 2023/10/19 22:58:16 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "Libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_line
{
	int	x1; //posición donde empieza la recta en x
	int	y1; //posición donde empieza la recta en y
	int	x2; //posición donde termina la recta en x
	int	y2; //posición donde termina la recta en x
	int	distx; //distancia entre x1 y x2
	int	disty; //distancia entre y1 e y2
	int	incrxincl; //incremento inclinacion de x (serán 1 ó -1 dependiendo de hacia donde vaya la linea)
	int	incryincl; //incremento inclinacion de y
	int	incrxrect; //incremetno en la recta x (serán 0 ó 1 dependiendo de si avanzan o no)
	int	incryrect; //incremetno en la recta y
	int	x; //posición de x mientras se dibuja la línea
	int	y; //posición de y mientras se dibuja la línea
	int	z1; //Supongo que la usaré para algo
	int	z2; //Calculo ambas y las meto acá en el readmap
}	t_line;

typedef struct s_map
{
	int	heigth;
	int	width;
	int	max_z;
	int	min_z;
	int	**map;
}	t_map;

//lines.c
void	bresenham_line(t_window *wnd, t_line *line);
void	draw_lines(t_window *wnd, t_line *line);
void	find_incl(t_line *line);
void	swap_values(t_line *line);
//readfile.c
void	count_heigth(t_map *map, char *str);
void	read_map(t_map *map, char *str);
void	save_map(t_map *map, char *line, size_t j);

#endif

/*s_line a;

a = create_nodo();
a -> y =
int b = a->jfojd;
a->b ... (*a).b
a es *struct
*/
