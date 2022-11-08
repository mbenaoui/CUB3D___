/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:03:53 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/11/23 22:08:15 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	benaoui(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	msimo(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*r;
	int		i;

	i = msimo(nbr);
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (0);
	r[i] = '\0';
	if (nbr < 0)
		r[0] = '-';
	else if (nbr == 0)
		r[0] = '0';
	while (nbr != 0)
	{
		--i;
		r[i] = benaoui(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (r);
}
