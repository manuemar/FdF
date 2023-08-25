/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:55:03 by manuemar          #+#    #+#             */
/*   Updated: 2023/08/25 12:54:01 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

int deal_key(int key, void *param)
{
	//if (key == 27)
		exit(1);
	//mlx_destroy_window(mlx, win);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = mlx_init(); //inicializar mlx
	win_ptr = mlx_new_window(mlx_ptr, 501, 501, "FdF"); //crear ventana con mlx, tamaño x en px, tamaño y en px, nombre ventana
	y = 0;
	while (y <= 500)
	{
		x = 0;
		while (x <= 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF); //pintar un pixel
			mlx_pixel_put(mlx_ptr, win_ptr, y, x, 0x151515); //pintar un pixel
			x++;
		}
		y += 30;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr); //pa que mande imagen constantemente
	return (0);
}

//gcc -Wall -Wextra -Werror main.c -Lmlx -lmlx -framework OpenGL -framework AppKit
//fg y ctrl c pa terminar ventana

// Estudiar El Algoritmo de Bresenham
	// Medir distancia de cada eje - el eje mayor avanzará siempre un pixel por vez (no habrá dos pixeles en paralelo, puesto que avanza más rapido)
	// En un bucle, el eje mayor avanzará en cada ciclo en dirección al punto final
	// El eje menor avanzará a veces 1 y a veces 0
	// Hay que calcular antes de empezar el bucle cuanto avanzará cada uno (obvio)
	// Restar el punto final al inicial

	// CONTINUAR DESDE: Solución de Bresenham para el avance específico del eje menor
	// EN https://es.wikipedia.org/wiki/Algoritmo_de_Bresenham#:~:text=El%20Algoritmo%20de%20Bresenham%20es,rasterizar%20tambi%C3%A9n%20circunferencias%20y%20curvas.

// Dibujar lineas en direcciones distitntas con coordenadas arbitrarias
// Leer mapas y sacar cordenadas
// Ya veré
