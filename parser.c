/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:52:29 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:28:57 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *filename)
{
	char	*line;
	char	**linenumbs;
	int		fd;
	int		width;

	width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	linenumbs = NULL;
	line = get_next_line(fd);
	if (line)
	{
		linenumbs = ft_split(line, ' ');
		free(line);
	}
	line = 0;
	while (linenumbs[width] != 0)
		width++;
	close(fd);
	clearlines(linenumbs);
	free(linenumbs);
	return (width);
}

int	get_height(char *filename)
{
	char	*line;
	char	**linenumbs;
	int		fd;
	int		height;

	height = 0;
	fd = open(filename, O_RDONLY);
	linenumbs = NULL;
	line = "a";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		height++;
	}
	close(fd);
	return (height - 1);
}

void	fillmatrix(char *filename, int **matrix, int width, int height)
{
	int		i;
	char	*line;
	char	**linenumbs;
	int		fd;
	int		j;

	i = -1;
	fd = open(filename, O_RDONLY);
	linenumbs = NULL;
	while (++i < height)
	{
		line = get_next_line(fd);
		if (line)
		{
			linenumbs = ft_split(line, ' ');
			free(line);
			j = -1;
			while (++j < width)
				matrix[i][j] = ft_atoi(linenumbs[j]);
			clearlines(linenumbs);
			free(linenumbs);
		}
	}
	close(fd);
}

int	**parser(char *filename, t_param *param)
{
	int	**matrix;
	int	width;
	int	height;
	int	i;

	i = 0;
	width = get_width(filename);
	height = get_height(filename);
	param->height = height;
	param->width = width;
	matrix = malloc(sizeof(int *) * (height));
	while (i < height)
	{
		matrix[i] = malloc(sizeof(int) * width);
		i++;
	}
	fillmatrix(filename, matrix, width, height);
	return (matrix);
}

// int main()
// {
// 	int **matrix;

// 	int i = 0;
// 	int j = 0;

// 	matrix = parser("42.fdf");

// 	for (i = 0; i < 11; i++)
// 	{
// 		for (j = 0; j < 19; j++)
// 		{
// 			printf("%d ", matrix[3][15]);
// 		}
// 		printf("\n");
// 	}
// }