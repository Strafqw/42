/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:16:27 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/30 20:25:13 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(const char *phrase, char c, char **newstr)
{
	size_t	i;
	size_t	words;

	words = 0;
	while (*phrase)
	{
		while (*phrase && *phrase == c)
			phrase++;
		if (*phrase)
		{
			i = 0;
			while (phrase[i] && phrase[i] != c)
				i++;
			if (i && newstr)
				newstr[words] = ft_substr(phrase, 0, i);
			words++;
			phrase += i;
		}
	}
	return (words);
}

void	*ft_free(char **str, size_t tmn)
{
	size_t	i;

	i = 0;
	while (i < tmn)
		free(str[i++]);
	return (free(str), NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;

	newstr = ft_calloc(countwords(s, c, NULL) + 1, sizeof(char *));
	countwords(s, c, newstr);
	return (newstr);
}
