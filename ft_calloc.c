/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:27:18 by micongiu          #+#    #+#             */
/*   Updated: 2024/02/02 16:07:17 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;

	if (n && size && n > (4294967295 / size))
		return (NULL);
	p = malloc(size * n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * n);
	return (p);
}
