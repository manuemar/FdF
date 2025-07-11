/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:55:03 by manuemar          #+#    #+#             */
/*   Updated: 2025/07/09 16:21:29 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

//Cerrar ventana
int	close_window(void)
{
	//mlx_destroy_window(mlx, win);
	exit(0);
	return (0);
}

//Funciones de teclas
int	ft_key_manage(int key, t_window *data)
{
	(void) data;
	ft_printf("%d\n", key);
	if (key == 53)
		close_window();
	return (0);
}
/**/
int	main(int argc, char **argv)
{
	t_window	data;
	t_line		line;
	t_map		map;

	if (argc != 2)
		return (ft_printf("Cantidad de argumentos inválida\n"), 0);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 690, "FdF");
	read_map(&map, argv[1]);
	//EMPEZAR A HACER FUNCIÓN CON BUCLE PARA DIBUJAR LAS LÍNEAS
	line.x1 = 0;
	line.y1 = 0;
	line.x2 = 500;
	line.y2 = 1000;
	bresenham_line(&data, &line); //ESTO IRA EN FUNCION A PARTE
	/*line.x1 = 900 - 75;
	line.y1 = 116;
	line.x2 = 900 - 686;
	line.y2 = 622;
	bresenham_line(&data, &line);*/ //ESTO IRA EN FUNCION A PARTE
	mlx_hook(data.win_ptr, 17, 1L << 17, &close_window, NULL);
	mlx_key_hook(data.win_ptr, ft_key_manage, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

/*
int	main(void)
{
	t_window	data;
	int		x;
	int		y;

//inicializar mlx
	data.mlx_ptr = mlx_init();
//crear ventana con mlx, tamaño x en px, tamaño y en px, nombre ventana
	data.win_ptr = mlx_new_window(data.mlx_ptr, 501, 501, "FdF");
	y = 0;
	while (y <= 500)
	{
		x = 0;
		while (x <= 500)
		{
//pintar un pixel
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFF00FF);
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, y, x, 0x00FF00);
			x++;
		}
		y += 30;
	}
	mlx_key_hook(data.win_ptr, deal_key, (void *)0);
	mlx_loop(data.mlx_ptr); //pa que mande imagen constantemente
	return (0);
}*/

//gcc -Wall -Wextra -Werror ./*.c -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit
//fg y ctrl c pa terminar ventana

//PARA SABER EL VALOR DE UNA TECLA, PRINTEAR EL VALOR DEL KEY_HOOK

// Estudiar El Algoritmo de Bresenham --
	// Medir distancia de cada eje - el eje mayor avanzará siempre un pixel
	//		por vez (no habrá dos pixeles en paralelo, puesto que avanza más rapido)
	// En un bucle, el eje mayor avanzará en cada ciclo en dirección al punto final
	// El eje menor avanzará a veces 1 y a veces 0
	// Hay que calcular antes de empezar el bucle cuanto avanzará cada uno (obvio)
	// Restar el punto final al inicial
	// El avance del eje menor puede ser 1 o 0 en cada ciclo, esto es 'inclinado'
	//		o 'recto', valor de incremento que debe ser actualizado en cada ciclo.

	// CONTINUAR DESDE: Pseudocódigo del algoritmo
	// EN https://es.wikipedia.org/wiki/Algoritmo_de_Bresenham#:~:text=El%20Algoritmo%20de%20Bresenham%20es,rasterizar%20tambi%C3%A9n%20circunferencias%20y%20curvas.

	// ALGORITMO DE XIAOLIN WU - ANTIALIASING
// Dibujar lineas en direcciones distitntas con coordenadas arbitrarias --
// Leer mapas y sacar cordenadas
// Cerrar ventanas POR FAVOR --
// Incluir antialiasin
// Cálculos para distintas vistas
// COLORES
// Ya veré
