/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializeAndClear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:44:38 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:40:41 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initializemlx(t_param *pe, t_hooker *hooker, char *str)
{
	hooker->matrix = parser(str, pe);
	pe->mlx_ptre = mlx_init();
	pe->win_ptre = mlx_new_window(pe->mlx_ptre,
			WINDOW_WIDTH, WINDOW_HEIGHT, "mi ferst windew");
	pe->img_ptre = mlx_new_image(pe->mlx_ptre, WINDOW_WIDTH, WINDOW_HEIGHT);
	pe->address = mlx_get_data_addr(pe->img_ptre,
			&pe->bitsperpixel, &pe->linesize, &pe->endian);
	pe->shiftx = 1000;
	pe->shifty = 100;
	pe->scale2zoom = 20;
	pe->color = COLOR;
	hooker->param = pe;
	hooker->param->rotx = 0;
	hooker->param->roty = 0;
	hooker->param->rotz = 0;
	hooker->param->iso = 1;
}
//to avoid segfault make this scalable with height and width of the map
//nvm just dont draw when its out of the window height and width

void	clearmatrix(int **matrix, t_param *param)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = param->height;
	width = param->width;
	while (i < height)
	{
		free(matrix[i]);
		matrix[i] = 0;
		i++;
	}
	free(matrix);
}

void	freestuff(t_hooker *hooker)
{
	if (hooker->matrix)
	{
		clearmatrix(hooker->matrix, hooker->param);
		hooker->matrix = 0;
	}
	mlx_destroy_image(hooker->param->mlx_ptre, hooker->param->img_ptre);
	mlx_clear_window(hooker->param->mlx_ptre, hooker->param->win_ptre);
	mlx_destroy_window(hooker->param->mlx_ptre, hooker->param->win_ptre);
	free(hooker->param->mlx_ptre);
	free(hooker->param);
	hooker->param = 0;
	free(hooker);
}

void	clearlines(char **linenumbs)
{
	int	i;

	i = 0;
	while (linenumbs[i])
		free(linenumbs[i++]);
}
//cant mlxdestroy+free