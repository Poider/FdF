/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:22 by mel-amma          #+#    #+#             */
/*   Updated: 2021/12/17 15:09:29 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (count);
	if (size > 0)
	{
		while (i + 1 < size && *src)
		{
			*dest++ = *src++;
			i++;
		}
	}
	*dest = '\0';
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (p == 0)
		return (0);
	ft_bzero(p, size * count);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	fill;
	unsigned char	*a;

	i = 0;
	fill = (unsigned char)c;
	a = s;
	while (i < n)
	{
		*a = fill;
		a++;
		i++;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	res;
	unsigned int			i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		if (res >= 9223372036854775807 && sign == -1)
			return (0);
	}
	return (res * sign);
}
