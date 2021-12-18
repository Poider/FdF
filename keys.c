/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:40:35 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:44:37 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotskeys(int button, t_hooker *hooker)
{
	if (button == 123)
		hooker->param->roty += 0.03;
	if (button == 126)
		hooker->param->rotx += 0.03;
	if (button == 124)
		hooker->param->rotz += 0.03;
	if (button == 0)
		hooker->param->roty -= 0.03;
	if (button == 13)
		hooker->param->rotx -= 0.03;
	if (button == 2)
		hooker->param->rotz -= 0.03;
}

void	scalekeys(int button, t_hooker *hooker)
{
	if (button == 37)
		hooker->param->shiftx += hooker->param->width / 2;
	if (button == 38)
		hooker->param->shiftx -= hooker->param->width / 2;
	if (button == 34)
		hooker->param->shifty -= hooker->param->height / 2;
	if (button == 40)
		hooker->param->shifty += hooker->param->height / 2;
	if (button == 67)
	hooker->param->iso = 2;
	if (button == 75)
	hooker->param->iso = 1;
}

void	zoomkeys(int button, t_hooker *hooker)
{
	if (button == 69)
	{
		hooker->param->scale2zoom += 1;
		hooker->param->color += 150420;
	}
	if (button == 78 && hooker->param->scale2zoom > 0)
	{
		hooker->param->scale2zoom -= 1;
		hooker->param->color -= 150420;
	}
	if (button == 53 || button == 17)
	{
		freestuff(hooker);
		exit(0);
	}
}

int	exitit(int button, t_hooker *hooker)
{
	t_hooker	*escapeunusedpar;

	escapeunusedpar = hooker;
	button = 1;
	exit(0);
	return (0);
}

//next params are used to avoid unused params