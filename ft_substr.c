/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:14:53 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/14 16:14:57 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nv;
	size_t	i;
	size_t	newlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	newlen = ft_strlen(s + start);
	if (newlen < len)
		len = newlen;
	nv = (char *)malloc(sizeof(char) * (len + 1));
	if (!nv)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		*(nv + i) = *(s + (start + i));
		i++;
	}
	nv[i] = '\0';
	return (nv);
}
