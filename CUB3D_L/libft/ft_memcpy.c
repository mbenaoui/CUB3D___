/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:34:32 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/12 23:19:01 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*m;
	const char	*b;
	size_t		i;

	m = dest;
	b = src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		m[i] = b[i];
		i++;
	}
	return (dest);
}
