/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:33:17 by timmi             #+#    #+#             */
/*   Updated: 2024/10/08 11:38:52 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **table, size_t x)
{
	while (x > 0)
		free(table[--x]);
	free(table);
}

static char	*fill_table(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static size_t	ft_wordcount(char *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	**table;

	x = 0;
	if (!s)
		return (NULL);
	table = malloc((ft_wordcount((char *)s, c) + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			table[x] = fill_table(s, c);
			if (!table[x])
				return (free_all(table, x), NULL);
			x++;
			while (*s && *s != c)
				s++;
		}
	}
	table[x] = NULL;
	return (table);
}
