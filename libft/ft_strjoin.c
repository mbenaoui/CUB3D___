/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:36:42 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:17:44 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_stlen( char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		m;
	size_t	len ;
	size_t	len1;
	char	*s4;

	i = 0;
	m = 0;
	if (!s1)
		return (0);
	len = ft_stlen(s1);
	len1 = ft_stlen(s2);
	s4 = (char *)ft_calloc(sizeof (char) , (len + len1 + 1));
	if (s4 == 0)
		return (0);
	while (s1[i])
		s4[m++] = s1[i++];
	i = 0;
	while (s2[i])
		s4[m++] = s2[i++];
	s4[m] = '\0';
	return (s4);
}
