/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:10:21 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:24 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void read_from_map(char *path, t_cub *cub)
{
    int i;
    char *str;

    i = 0;
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        msg_error(0);
    while (1)
    {
        cub->lines[i] = get_next_line(fd);
        if (!cub->lines[i])
            break;
        if (cub->lines[i][0] != '\n')
        {
            str = cub->lines[i];
            cub->lines[i] = ft_strtrim(cub->lines[i], "\n");
            free(str);
        }
        i++;
    }
    cub->lines[i] = NULL;
}

void check_color_and_texture(t_cub *cub)
{
    if (!cub->fd_ea || !cub->fd_no || !cub->fd_so || !cub->fd_we)
        msg_error(2);
    if (cub->rgb_c->_r < 0 || cub->rgb_c->_r > 255)
        msg_error(4);
    if (cub->rgb_c->_g < 0 || cub->rgb_c->_g > 255)
        msg_error(4);
    if (cub->rgb_c->_b < 0 || cub->rgb_c->_b > 255)
        msg_error(4);
    if (cub->rgb_f->_r < 0 || cub->rgb_f->_r > 255)
        msg_error(4);
    if (cub->rgb_f->_g < 0 || cub->rgb_f->_g > 255)
        msg_error(4);
    if (cub->rgb_f->_b < 0 || cub->rgb_f->_b > 255)
        msg_error(4);
}

void copy_lines_in_map(t_cub *cub, int i)
{
    int j;

    j = 0;
    cub->map = ft_calloc(sizeof(char *), (cub->size1 - i) + 1);
    while (cub->lines[i])
        cub->map[j++] = ft_strdup(cub->lines[i++]);
    cub->map[j] = NULL;
    cub->size2 = len_tab(cub->map, 1);
}

void check_map_valid(t_cub *cub, char *path)
{
    int fd;
    int len;
    int i;
    i = 0;
    cub->size1 = size_map(path);
    cub->lines = ft_calloc(sizeof(char *), (cub->size1 + 2));
    read_from_map(path, cub);
    cub->fd_ea = NULL;
    cub->fd_no = NULL;
    cub->fd_so = NULL;
    cub->fd_we = NULL;
    i = handling_texture(cub, 0, 0);
     copy_lines_in_map(cub, i);
    check_may_map(cub->map, -1, -1, 0);
    check_color_and_texture(cub);
}
