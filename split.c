/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:30:27 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/11 16:33:47 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	words_numb(char *s, char del)
{
	int	count;
	int	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	if (s[i] == del)
		i++;
	while (s[i])
	{
		if (s[i] == del)
			count++;
		i++;
	}
	return (count + 1);
}

int	ft_length(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	return (i);
}

void	freeit(char **arr, int size)
{
	while (size)
		free(arr[--size]);
	free(arr);
	arr = 0;
}

void	splitit(char **arr, int len, char *str, char c)
{
	int	flag;
	int	size;
	int	i;

	size = 0;
	flag = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != c && flag == 0)
		{
			len = ft_length(&str[i], c);
			flag = 1;
			arr[size] = (char *)malloc((len + 1) * sizeof(char));
			if (!arr[size])
			{
				freeit(arr, size);
				return ;
			}
			ft_strlcpy(arr[size++], &str[i], len + 1);
		}
		else if (str[i] == c)
			flag = 0;
	}
	arr[size] = 0;
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		len;

	if (!str)
		return (0);
	len = 0;
	arr = (char **)malloc(words_numb(str, c) * (sizeof(char *) + 1));
	if (!arr)
		return (0);
	splitit(arr, len, str, c);
	return (arr);
}
