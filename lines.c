/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:04 by manuemar          #+#    #+#             */
/*   Updated: 2023/10/19 23:51:56 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

/*int	get_color(t_line *line)
{

}*/

void	draw_lines(t_window *wnd, t_line *line)
{
	int	av;
	int	avrect;
	int	avincl;
	//int	color;

	avrect = 2 * line->disty;
	av = avrect - line->distx;
	avincl = av - line->distx;
	while (line->x != line->x2 || line->y != line->y2)
	{
		//color = get_color(line);
		mlx_pixel_put(wnd->mlx_ptr, wnd->win_ptr, line->x, line->y, 0xFF00FF);
		if (av >= 0)
		{
			line->x += line->incrxincl;
			line->y += line->incryincl;
			av += avincl;
		}
		else
		{
			line->x += line->incrxrect;
			line->y += line->incryrect;
			av += avrect;
		}
	}
}

void	swap_values(t_line *line)
{
	int	k;

	k = line->distx;
	line->distx = line->disty;
	line->disty = k;
}

void	find_incl(t_line *line)
{
	if (line->disty >= 0)
		line->incryincl = 1;
	else
	{
		line->disty *= -1;
		line->incryincl = -1;
	}
	if (line->distx >= 0)
		line->incrxincl = 1;
	else
	{
		line->distx *= -1;
		line->incrxincl = -1;
	}
	if (line->distx >= line->disty)
	{
		line->incryrect = 0;
		line->incrxrect = line->incrxincl;
	}
	else
	{
		line->incrxrect = 0;
		line->incryrect = line->incryincl;
	}
}

void	bresenham_line(t_window *wnd, t_line *line)
{
	line->distx = line->x2 - line->x1;
	line->disty = line->y2 - line->y1;
	find_incl(line);
	if (line->disty > line->distx)
		swap_values(line);
	line->x = line->x1;
	line->y = line->y1;
	draw_lines(wnd, line);
}
