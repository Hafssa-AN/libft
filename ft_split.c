/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:53:16 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/15 11:53:41 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*new_word(const char *s, int *i, char c)
{
	int		j;
	int		start;
	int		len;
	char	*words;

	len = ft_strlen(s);
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	words = (char *)malloc ((*i - start) + 1);
	if (words == NULL)
		return (NULL);
	j = 0;
	while (start < *i)
	{
		words[j] = s[start];
		start++;
		j++;
	}
	words[j] = '\0';
	return (words);
}

static char	**free_words(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = malloc ((count_words(s, c) + 1) * sizeof (char *));
	if (words == NULL)
		return (NULL);
	j = 0;
	while (j < count_words(s, c) && s[i])
	{
		if (s[i] != c)
		{
			words[j] = new_word(s, &i, c);
			if (words[j] == NULL)
				return (free_words(words, (j - 1)));
			j++;
		}
		i++;
	}
	words[j] = NULL;
	return (words);
}
