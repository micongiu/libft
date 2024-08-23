/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:53:54 by micongiu          #+#    #+#             */
/*   Updated: 2024/02/06 16:23:52 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
			count ++;
		while (s[i] && s[i] != c)
			i ++;
	}
	return (count);
}

int	check_mem(char **matrix, int j)
{
	if (matrix[j] == NULL)
	{
		while (j >= 0)
		{
			free(matrix[j]);
			j--;
		}
	}
	return (1);
}

int	fill_matrix(char **matrix, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		while (s[i++] == c)
			pos++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (words != 0)
		{
			matrix[j] = ft_substr(s, pos, i - pos);
			if (matrix[j] == NULL)
				return (check_mem(matrix, j));
			pos = i + 1;
			i++;
			j++;
			words--;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	matrix = (char **) malloc((words + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	if (fill_matrix(matrix, s, c, words) == 1)
	{
		free(matrix);
		return (NULL);
	}
	matrix[words] = NULL;
	return (matrix);
}
