/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:01:14 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/15 18:02:36 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int x)
{
	int	count;

	if (x == 0)
		return (1);
	count = 0;
	if (x < 0)
		count++;
	while (x != 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nn;
	char	*str;

	nn = n;
	len = intlen(n);
	str = (char *)malloc(sizeof(char) * (intlen(n) + 1));
	if (!str)
		return (0);
	if (nn < 0)
	{
		str[0] = '-';
		nn *= -1;
	}
	str[len] = '\0';
	if (nn == 0)
		str[0] = '0';
	while (nn != 0)
	{
		str[--len] = (nn % 10) + 48;
		nn /= 10;
	}
	return (str);
}
