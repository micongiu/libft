/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:02:07 by micongiu          #+#    #+#             */
/*   Updated: 2024/02/02 17:32:24 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub_s = malloc (1);
		*sub_s = '\0';
		return (sub_s);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	sub_s = malloc (len + 1);
	i = 0;
	if (sub_s == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[len] = '\0';
	return (sub_s);
}
