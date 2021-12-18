/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:27 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 14:59:32 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define COLOR 301456875

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_param //has map + image infos
{
	void	*mlx_ptre;
	void	*win_ptre;
	void	*img_ptre;
	t_point	point;
	int		width;
	int		height;
	char	*address;
	int		endian;
	int		bitsperpixel;
	int		linesize;
	int		iso;
	int		color;
	float	rotx;
	float	roty;
	float	rotz;
	int		shiftx;
	int		shifty;
	int		scale2zoom;
}			t_param;

//width and height are matrix ones

typedef struct s_hooker
{
	int		**matrix;
	t_param	*param;
}				t_hooker;

//helpers
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi(const char *str);

//split
char	**ft_split(char *str, char c);

//fdf
int		absolute(int a);
void	initbresenham(t_point start, t_point end,
			t_point *sign, t_point *delta);
void	bresenham(t_param *param, t_point start, t_point end, int **matrix);
void	drawloop(t_param *param, int **matrix, int x, int y);
void	drawit(t_param *param, int **matrix);

// //reader
// char **readline(int fd);
// char **getwidth(int *widthreturn, int fd);
// void processline(int fd, int *height, int *width);
// void getsize(char *str, int *height, int *width);

//initializeAndClear
void	initializemlx(t_param *pe, t_hooker *hooker, char *str);
void	clearmatrix(int **matrix, t_param *param);
void	freestuff(t_hooker *hooker);
void	clearlines(char **linenumbs);

//keys
void	rotskeys(int button, t_hooker *hooker);
void	scalekeys(int button, t_hooker *hooker);
void	zoomkeys(int button, t_hooker *hooker);
int		exitit(int button, t_hooker *hooker);

//parser
int		get_width(char *filename);
int		get_height(char *filename);
void	fillmatrix(char *filename, int **matrix, int width, int height);
int		**parser(char *filename, t_param *param);
// //drawlines
// int **printmatrix(t_param *param, int color, int pointdistance );

//pointsmanipulation
void	rotation(int *x, int *y, double teta, t_param *param);
void	image_pixel_put(t_param *param, t_point point, int color, int **matrix);
void	isometry(int *x, int *y, int z);
t_point	makepoint(int x, int y, int **matrix);
t_point	cooardinates(t_point point, t_param *param);

//screen
void	put_menu(t_param *param);
int		renderagain(int button, t_hooker *hooker);

//writers
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif