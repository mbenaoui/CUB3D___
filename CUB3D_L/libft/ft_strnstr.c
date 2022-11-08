/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:01:31 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:19:32 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *dest, size_t len)
{
	char	*m;
	char	*b;
	size_t	i;
	int		j;

	m = (char *)dest;
	b = (char *)src;
	i = 0;
	j = 0;
	if (m[j] == '\0' || m == NULL)
		return (b);
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (src[i + j] && src[i + j] == dest[j] && i + j < len)
		{
			if (dest[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
