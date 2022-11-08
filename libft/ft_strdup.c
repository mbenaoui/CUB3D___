/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:34:36 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:17:01 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		n;
	int		i;

	n = 0 ;
	while (s1[n])
		n++;
	c = ft_calloc(sizeof(char) , (n + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (i < n)
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
