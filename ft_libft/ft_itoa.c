/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:16:02 by bsouhar           #+#    #+#             */
/*   Updated: 2022/11/21 01:42:11 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	in;

	i = counter(n);
	in = (long int)n;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (in == 0)
		str[0] = in + 48;
	if (in < 0)
	{
		str[0] = '-';
		in = -in;
	}
	while (in)
	{
		str[i] = (in % 10) + 48;
		in /= 10;
		i--;
	}
	return (str);
}
