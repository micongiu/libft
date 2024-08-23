/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:09 by micongiu          #+#    #+#             */
/*   Updated: 2024/02/01 18:03:57 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s_dest;
	size_t	b;
	size_t	s_src;

	if (!src && !dest)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	s_dest = ft_strlen(dest);
	b = 0;
	s_src = ft_strlen(src);
	if (size < s_dest)
		return (s_src + size);
	while (src[b] != '\0' && s_dest + 1 < size)
	{
		dest[s_dest] = src[b];
		s_dest++;
		b++;
	}
	dest[s_dest] = '\0';
	return (ft_strlen(&src[b]) + s_dest);
}
