/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:12:51 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/14 16:18:53 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "fdf.h"
//positive slope
void linealgo(int xa, int ya, int xb, int yb)//make sure to send xa and ya < xb and yb // pretty much for positive slope only
{
	int deltax;
	int deltay;
	int pk;
	int x = xa;
	int y = ya;

	deltax = xb - xa;
	deltay = yb - ya; // compare delatas to know the slope then redirect to the slope 
	pk = 2*deltay - deltax;

	while(x != xb)
	{
		if(pk < 0)
		{	
			pk = pk + 2*deltay; 
			x = x + 1;
			y = y;
		}
		else
		{
			pk = 2* deltay - 2*deltax;
			x = x + 1;
			y = y + 1;
		}

		printf("%d %d \n", x , y);
	}
}// apparently when x is bigger than y?.. m < 1?


//negative slope


// void negalinealgo()
// {

// }
// straight line, down or up
int **printmatrix(tparam *param, int color, int pointdistance )
{
	int height;
	int width;
	int y = 0; // coordinates where to start printing
	int x = 0;
	int i = 0;
	int **matrix;
	getsize("42.fdf", &height, &width);
	matrix = ft_calloc(height,sizeof(int *));
	width = width * pointdistance;
	height = height * pointdistance;
	
	printf("height : %d\n",height);
	while(y < height)
	{
		x = 0;
		matrix[i++] = ft_calloc(width,sizeof(int));
		while(x < width)
		{	
			
			printf("x : %d y : %d\n", x,y);
			image_pixel_put(param,x*cos(1),y + x*cos(1),color);
			x = x + pointdistance; //iterate with the size of the line they want in here and in y;
		}
		y = y + pointdistance;
	}
		mlx_put_image_to_window(param->mlx_ptre, param->win_ptre, param->img_ptre, 0, 0);
		return matrix;
}


 positive slope negative slope  + is it on the right or the left of the 1 / -1 slope 
+ of straight line up or sideway
*/