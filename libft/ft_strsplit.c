/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:59:27 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 16:57:00 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *str, char delimiter)
{
	int	wc;
	int	i;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != delimiter && str[i - 1] == delimiter) ||
			(str[i] != delimiter && i == 0))
			wc++;
		i++;
	}
	return (wc);
}

static int	is_new(int i, char *str, char delimiter)
{
	return (i > 0 && str[i - 1] != delimiter);
}

static int	*get_words_size(char *str, char delimiter)
{
	int	i;
	int	j;
	int	wc;
	int	*sizes;

	i = 0;
	wc = countwords(str, delimiter) + 1;
	if (!(sizes = (int *)malloc(wc * sizeof(int))))
		return (NULL);
	while (i < wc)
	{
		sizes[i] = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
			sizes[j]++;
		else if (is_new(i, str, delimiter))
			j++;
		i++;
	}
	return (sizes);
}

static char	**ft_bouillasse(char *str, char delimiter, char **words, int *sizes)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != delimiter)
		{
			if (i == 0 || (str[i] != delimiter && str[i - 1] == delimiter))
			{
				if (!(words[k] = ft_strnew(sizes[k])))
					return (NULL);
			}
			words[k][j++] = str[i];
		}
		else if (is_new(i, str, delimiter) && ++k)
			j = 0;
	}
	if (k == 0 && sizes[k] == 0)
		words[k] = 0;
	return (words);
}

char		**ft_strsplit(char const *s, char delimiter)
{
	char	**words;
	int		*sizes;
	char	*str;
	int		word_nb;

	if (!s)
		return (NULL);
	str = (char *)s;
	word_nb = countwords(str, delimiter);
	if (!(words =
		(char **)malloc((word_nb + 1) * sizeof(char *))))
		return (NULL);
	sizes = get_words_size(str, delimiter);
	if (!sizes)
		return (NULL);
	words = ft_bouillasse(str, delimiter, words, sizes);
	free(sizes);
	if (words[word_nb] != 0)
		words[word_nb] = 0;
	return (words);
}
