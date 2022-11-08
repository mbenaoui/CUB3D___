/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:40:43 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:13:25 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m;
	unsigned char	*b;
	size_t			i ;

	m = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (m[i] != b[i])
			return (m[i] - b[i]);
		i++;
	}
	return (0);
}
