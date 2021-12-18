/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:42:13 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:24:15 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 15, 130140150, "Rotate around (x,y,z): A-W-D");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 30, 130140150, "Reverse rotate around (x,y,z): UP-RIGHT-LEFT");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 45, 130140150, "Zoom : + -");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 60, 130140150, "Shift : I-J-K-L");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 75, 130140150, "Swap projection: / *");
}

int	renderagain(int button, t_hooker *hooker)
{
	if (hooker->param->img_ptre)
	{
		mlx_destroy_image(hooker->param->mlx_ptre, hooker->param->img_ptre);
		hooker->param->img_ptre = 0;
	}
	hooker->param->img_ptre = mlx_new_image(hooker->param->mlx_ptre,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	hooker->param->address = mlx_get_data_addr(hooker->param->img_ptre,
			&hooker->param->bitsperpixel,
			&hooker->param->linesize, &hooker->param->endian);
	mlx_clear_window(hooker->param->mlx_ptre, hooker->param->win_ptre);
	rotskeys(button, hooker);
	scalekeys(button, hooker);
	zoomkeys(button, hooker);
	drawit(hooker->param, hooker->matrix);
	put_menu(hooker->param);
	return (0);
}
