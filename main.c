/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:47:50 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:39:20 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{	
	t_param		*pe;
	t_hooker	*hooker;

	if (argc != 2)
	{
		ft_putstr("Error, Enter file name alone");
		return (0);
	}
	pe = malloc(sizeof(t_param));
	hooker = malloc(sizeof(t_hooker));
	initializemlx(pe, hooker, argv[1]);
	drawit(pe, hooker->matrix);
	mlx_hook(pe->win_ptre, 02, 0L, renderagain, hooker);
	mlx_hook(pe->win_ptre, 17, 0L, exitit, hooker);
	put_menu(pe);
	mlx_loop(pe->mlx_ptre);
	freestuff(hooker);
	system("leaks fdf");
	return (0);
}

//fillin struct
//pointers

//imageinfos

//isometry(pe->height,pe->width,hooker->matrix[pe->height][pe->width]);