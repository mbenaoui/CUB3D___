/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:33:37 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:18:14 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strle(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	char	*s;
	size_t	r;

	s = (char *)src;
	d = ft_strle(dst);
	i = 0;
	if (dstsize <= ft_strle(dst))
	r = ft_strle(s) + dstsize;
	else
	r = ft_strle(s) + ft_strle(dst);
	while ((d + 1 < dstsize) && (s[i] != '\0'))
	{
		dst[d] = s[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (r);
}
