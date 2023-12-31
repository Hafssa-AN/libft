/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:04:38 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/14 22:06:07 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_null(char const *s1, char const *set)
{
	if (!set)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	t;
	char	*p;

	if (!s1 || !set)
		return (is_null(s1, set));
	i = 0;
	j = ft_strlen(s1);
	t = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < j && ft_strchr(set, s1[j - 1]))
		j--;
	p = (char *)malloc(sizeof(char) * j - i + 1);
	if (!p)
		return (NULL);
	while (s1[i] && t < j - i)
	{
		p[t] = s1[i + t];
		t++;
	}
	p[t] = '\0';
	return (p);
}
