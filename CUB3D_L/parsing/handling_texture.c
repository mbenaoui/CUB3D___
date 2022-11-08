/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:09:37 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:08 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	skip_esp(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '/')
			break ;
		i++;
	}
	return (i);
}

void	search_textures(t_cub *cub, char *path, int *j, int index)
{
	path = path + skip_esp(path);
	if (index == 0)
	{
		if (-1 != open(path, O_RDONLY))
			cub->fd_no = path;
	}
	else if (index == 1)
	{
		if (-1 != open(path, O_RDONLY))
			cub->fd_so = path;
	}
	else if (index == 2)
	{
		if (-1 != open(path, O_RDONLY))
			cub->fd_we = path;
	}
	else if (index == 3)
		if (-1 != open(path, O_RDONLY))
			cub->fd_ea = path;
	(*j)++;
}

void	handling_texture_2(char **str, int *j, t_cub *cub, int i)
{
	if (!ft_strcmp(str[0], "NO") && str[1] && !cub->fd_no)
		search_textures(cub, cub->lines[i], j, 0);
	else if (!ft_strcmp(str[0], "SO") && str[1] && !cub->fd_so)
		search_textures(cub, cub->lines[i], j, 1);
	else if (!ft_strcmp(str[0], "WE") && str[1] && !cub->fd_we)
		search_textures(cub, cub->lines[i], j, 2);
	else if (!ft_strcmp(str[0], "EA") && str[1] && !cub->fd_ea)
		search_textures(cub, cub->lines[i], j, 3);
	else if (!ft_strcmp(str[0], "C"))
		search_color(cub, cub->lines[i], j, 0);
	else if (!ft_strcmp(str[0], "F"))
		search_color(cub, cub->lines[i], j, 1);
	else
		msg_error(1);
}

int	handling_texture(t_cub *cub, int i, int j)
{
	char	**str;

	while (cub->lines[i])
	{
		if (cub->lines[i][0] == '\n')
		{
			i++;
			continue ;
		}
		str = ft_split(cub->lines[i], ' ');
		if (str[0][0] == '1' && str[0][ft_strlen(str[0]) - 1] == '1')
		{
			free_tab(str);
			break ;
		}
		handling_texture_2(str, &j, cub, i);
		free_tab(str);
		i++;
	}
	if (j != 6)
		msg_error(1);
	return (i);
}
