/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:11:01 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:27:23 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void renderline()
// {

// }

// void drawline(int x, int y, t_param param)
// {
// 	// you can calculate isometry then draw the line between those two points or
// 	// draw the line between (x,y) and (param -> x, param -> y)

// 	//get every point between those two points then pixelput every point
// 	// in it isometric value

// }

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	initbresenham(t_point start, t_point end, t_point *sign, t_point *delta)
{
	delta->x = absolute(end.x - start.x);
	delta->y = absolute(end.y - start.y);
	if (end.x > start.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (end.y > start.y)
		sign->y = 1;
	else
		sign->y = -1;
}

void	bresenham(t_param *param, t_point start, t_point end, int **matrix)
{
	t_point	cursor;
	t_point	delta;
	t_point	sign;
	int		decisionpar;
	int		temporary;

	cursor = start;
	initbresenham(start, end, &sign, &delta);
	decisionpar = delta.x - delta.y;
	while (cursor.x != end.x || cursor.y != end.y)
	{
		temporary = 2 * decisionpar;
		image_pixel_put(param, cursor, 0, matrix);
		if (temporary > -delta.y)
		{
			decisionpar -= delta.y;
			cursor.x += sign.x;
		}
		if (temporary < delta.x)
		{
			decisionpar += delta.x;
			cursor.y += sign.y;
		}
	}
}

// here where it used to bug
//cus I would not use a temp var and decision
//parameter would change on the next 2*decisionpar

/* Modify this to get the step jumps * with height
 and width then iterate with it instead of +1 */
/* HEIGHT AND WIDTH HERE IS THE MATRIX NOT THE IMAGE/WINDOW*/

void	drawloop(t_param *param, int **matrix, int x, int y)
{
	while (++y < param->height)
	{
		x = 0;
		while (x < param->width)
		{
			if (x < param->width - 1)
			{
				param->point.x = x + 1;
				param->point.y = y;
				bresenham(param, cooardinates(makepoint(x, y, matrix), param),
					cooardinates(makepoint(param->point.x, param->point.y,
							matrix), param), matrix);
			}
			if (y < param->height - 1)
			{
				param->point.x = x;
				param->point.y = y + 1;
				bresenham(param, cooardinates(makepoint(x, y, matrix), param),
					cooardinates(makepoint(param->point.x, param->point.y,
							matrix), param), matrix);
			}
			x++;
		}
	}
}

void	drawit(t_param *param, int **matrix)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	drawloop(param, matrix, x, y);
	mlx_put_image_to_window(param->mlx_ptre,
		param->win_ptre, param->img_ptre, 0, 0);
}
