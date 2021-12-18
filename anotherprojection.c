// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   anotherprojection.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/17 09:42:02 by mel-amma          #+#    #+#             */
// /*   Updated: 2021/12/17 10:10:48 by mel-amma         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// void project(tparam *param,t_point point, t_point point)
// {
// 	t_point cursor;
// 	t_point delta;
// 	t_point sign;
// 	int decisionpar;
// 	int temporary;
	
// 	cursor = start;
// 	initbresenham(start, end, &sign, &delta);
// 	decisionpar = delta.x - delta.y;
// 	while(cursor.x != end.x || cursor.y != end.y) // it can either go up to it or down to it
// 	{
// 		temporary = 2*decisionpar; // here where it used to bug cus I would not use a temp var and decision parameter would change on the next 2*decisionpar
// 		image_pixel_put(param,cursor.x,cursor.y,0,matrix);
// 		if(temporary > -delta.y)
// 		{
// 			decisionpar -= delta.y;
// 			cursor.x += sign.x;
// 		}
// 		if(temporary < delta.x)
// 		{
// 			decisionpar += delta.x;
// 			cursor.y += sign.y;
// 		}
// 	}
// }

// void drawitagain(tparam *param, int **matrix) /* Modify this to get the step jumps * with height and width then iterate with it instead of +1 */
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	/* 					HEIGHT AND WIDTH HERE IS THE MATRIX NOT THE IMAGE/WINDOW		*/
// 	while (y < param->height)
// 	{
// 		x = 0;
// 		while (x < param->width)
// 		{
// 			if (x < param->width - 1)
// 			{
// 				param->point.x = x + 1;
// 				param->point.y = y;
// 				project(param,makepoint(x,y,matrix),makepoint(param->point.x,param->point.y,matrix));
				
// 			}
// 			if (y < param->height - 1)
// 			{
// 				param->point.x = x;
// 				param->point.y = y + 1;
// 				project(param,makepoint(x,y,matrix),makepoint(param->point.x,param->point.y,matrix));
				
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(param -> mlx_ptre, param ->win_ptre, param ->img_ptre,0,0);
// }