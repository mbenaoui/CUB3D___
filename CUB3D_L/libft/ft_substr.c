/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:34:46 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:20:55 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*b;
	size_t			j;
	size_t			i;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		b = ft_calloc (ft_strlen(s) , sizeof(*s));
	else
		b = ft_calloc (len + 1 , sizeof(*s));
	if (b == 0)
		return (0);
	while (s[j])
	{
		if (j >= start && i < len)
		{
			b[i] = s[j];
			i++;
		}
		j++;
	}
	b[i] = 0;
	return (b);
}
