/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:18 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/12 18:44:18 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] && (i + dstlen) < dstsize - 1)
	{
		dst[i + dstlen] = src[i];
		i++; 
	}
	dst[i + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
