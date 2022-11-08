/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:10:50 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:54 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void msg_error(int status)
{
    if (status == 0)
        ft_putendl_fd("cub3d : No such file or directory", 2);
    if (status == 1)
        ft_putendl_fd("cub3d :map invalid (< >)", 2);
    if (status == 2)
        ft_putendl_fd("cub3d :texture not found !", 2);
    if (status == 3)
        ft_putendl_fd("cub3d :color not fond !", 2);
    if (status == 4)
        ft_putendl_fd("cub3d :color kharij atartya !", 2);
    if (status == 5)
        ft_putendl_fd(" Cub3d : character not in define !", 2);
    if (status == 6)
        ft_putendl_fd("cub3d : problem in number of player (khona 9alt lk za3ma ra 3andk xi moxkil fi 3adad dayl player sf ghayrha) !", 2);
    exit(1);
}

int size_map(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        msg_error(0);
    char buf[1];
    int len;
    len = 0;
    int flag = 0;
    while (read(fd, buf, 1))
    {
        if (buf[0] == '\n')
            len++;
        flag = 1; 
    }
    if (flag == 0)
        msg_error(1);
    return len;
}



void handling_color(t_cub *cub, char *des, int index, int i)
{

    if (index == 0)
    {
        if (i == 0)
            cub->rgb_c->_r = ft_atoi(des);
        else if (i == 1)
            cub->rgb_c->_g = ft_atoi(des);
        else if (i == 2)
            cub->rgb_c->_b = ft_atoi(des);
    }
    else if (index == 1)
    {
        if (i == 0)
            cub->rgb_f->_r = ft_atoi(des);
        else if (i == 1)
            cub->rgb_f->_g = ft_atoi(des);
        else if (i == 2)
            cub->rgb_f->_b = ft_atoi(des);
    }
}

void check_color(t_var var)
{
    var.k = 0;
    var.y = 0;
    while (var.tab[var.i][var.y])
    {
        if ((var.tab[var.i][var.y] == ' ' && ft_isdigit(var.tab[var.i][var.y + 1])))
            var.k++;
        if ((var.tab[var.i][var.y] != ' ' && !ft_isdigit(var.tab[var.i][var.y])) || var.k == 2)
            msg_error(3);
        var.y++;
    }
}

void search_color(t_cub *cub, char *str, int *j, int index)
{
    t_var var;
    var.i = 0;
    while (str[var.i] == ' ')
        var.i++;
    str = str + var.i;
    if(str[ft_strlen(str) - 1] == ',')
            msg_error(1);
    var.tab = ft_split(str + 1, ',');
    len_tab(var.tab, 0);
    var.i = 0;
    while (var.tab[var.i])
    {
        check_color(var);
        handling_color(cub, var.tab[var.i], var.i, index);
        var.i++;
    }
    (*j)++;
    free_tab(var.tab);
}

