/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:13:09 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/12 12:28:15 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(const char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			words++;
			while (*str && *str != c)
				str++;
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
	free(str);
	return (NULL);
}

static char	**fill_words(const char *s, char c, char **arr)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return (ft_free(arr, i));
		i++;
		s += len;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = countwords(s, c);
	arr = ft_calloc(wordcount + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_words(s, c, arr));
}

/*int main(void)
{
	char **result;
	int i;

	i = 0;
	result = ft_split(" Hello W Orld", ' ');
	if (!result)
	{
		printf("Allocation Failed\n");
		return (1);
	}
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/