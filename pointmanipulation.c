/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointmanipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:09:08 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:29:16 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(int *x, int *y, double teta, t_param *param)
{
	int	savex;
	int	savey;

	savex = *x;
	savey = *y;
	savex -= (param->height / 2) * param->scale2zoom;
	savey -= (param->width / 2) * param->scale2zoom;
	*x = savex * cos(teta) - savey * sin(teta);
	*y = savey * cos(teta) + savex * sin(teta);
	*x += (param->height / 2) * param->scale2zoom;
	*y += (param->width / 2) * param->scale2zoom;
}

// void image_clear(t_param *param)
// {
// 	char *pixel;
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while (y < WINDOW_HEIGHT)
// 	{
// 		while (x < WINDOW_WIDTH)
// 		{
// 			pixel = param->address + (y * (param->linesize) +
// x * (param->bitsperpixel) / 8);
// 			*(int *)pixel = 202202202;
// 			x++;
// 		}
// 		y++;
// 	}
// }

//using matrix in imagepixelput to avoid unused

//x,y are pixel coordinates 
void	image_pixel_put(t_param *param, t_point point, int color, int **matrix)
{
	char	*pixel;
	int		x;
	int		y;
	int		z;

	x = point.x;
	y = point.y;
	z = matrix[0][0];
	if (param->iso != 1)
		color = 1;
	if (x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		pixel = param->address + (y * (param->linesize)
				+ x * (param->bitsperpixel) / 8);
		if (!color)
			*(int *)pixel = param->color;
		else
			*(int *)pixel = COLOR + point.z / (param->scale2zoom / 2) * 1500;
	}
}

//printf("%d ",point.z/(param->scale2zoom/2));
//mlx_pixel_put(param ->mlx_ptre,param-> win_ptre,x,y,color);
// ft_putstr(img ->address);
//printf("%d ",x - param->shiftx);

void	isometry(int *x, int *y, int z)
{
	int	xsave;
	int	ysave;

	xsave = *x;
	ysave = *y;
	*x = (xsave - ysave) * cos(0.7);
	*y = (xsave + ysave) * sin(0.7) - z;
}

// l-83.was wrong here cus I didnt save em so they got overwritten 
//and I got the d in the ass for so

t_point	makepoint(int x, int y, int **matrix)
{
	t_point	newpoint;

	newpoint.x = x;
	newpoint.y = y;
	newpoint.z = matrix[newpoint.y][newpoint.x];
	return (newpoint);
}

t_point	cooardinates(t_point point, t_param *param)
{
	point.x *= param->scale2zoom * 2;
	point.y *= param->scale2zoom * 2;
	point.z *= param->scale2zoom / 2;
	rotation(&point.x, &point.y, param->rotz, param);
	rotation(&point.y, &point.z, param->rotx, param);
	rotation(&point.z, &point.x, param->roty, param);
	if (param->iso == 1)
		isometry(&point.x, &point.y, point.z);
	point.x += param->shiftx;
	point.y += param->shifty;
	return (point);
}

// int main()
// {
// 	t_point pointe;

// 	pointe.x = 4;
// 	pointe.y = 6;
// 	pointe = cooardinates(pointe,(int **)0, 0);
// 	printf(" x : %d, y : %d \n", pointe.x,pointe.y);
// }