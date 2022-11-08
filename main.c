#include "include/cub3d.h"
void calcul_end_x_y(t_cub *cub)
{
    int x;
    int y;
    x = cub->player.beg_x;
    y = cub->player.beg_y;
    while (1)
    {
        y = y - 64;
        if (cub->map[y / 64] && cub->map[y / 64][x / 64] == '1')
        {
            cub->player.end_x = x;
            cub->player.end_y = y + 64;
            break;
        }
    }
}
/*
int move(int key, t_cub *cub)
{
     
    int x;
    int y;
    if (key == 123)
    {
        if(cub->c == 2)
             cub->player.rotaionagngle -= 0.1;
        mlx_clear_window(cub->mlx, cub->window);
        white_window(cub);
        paint_wall(cub);

        double angel; //= cub->player.rotaionagngle;
        double i = 0;
        double max_angle = FOV / 2;
        i = cub->player.rotaionagngle - max_angle;
        while (i < cub->player.rotaionagngle + max_angle)
        {
            x = cub->player.beg_x + cos(i) * 64;
            y = cub->player.beg_y + sin(i) * 64;
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, cub->player.beg_x, cub->player.beg_y - 10, 0x00000000);
            draw_line(cub, cub->player.beg_x + 5, cub->player.beg_y, cub->player.beg_x + 5, cub->player.beg_y, 0x00ff0ff00);
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, x, y, 0x00ff0ff00);
            i += 0.15;
        }
         cub->player.rotaionagngle =cub->player.rotaionagngle -  0.15;
    }
    if (key == 124)
    {
        if(cub->c == 2)
             cub->player.rotaionagngle += 0.1;
        mlx_clear_window(cub->mlx, cub->window);
        white_window(cub);
        paint_wall(cub);

        double angel; //= cub->player.rotaionagngle;
        double i = 0;
        double max_angle = FOV / 2;
        i = cub->player.rotaionagngle - max_angle;
        while (i < cub->player.rotaionagngle + max_angle)
        {
            x = cub->player.beg_x + cos(i) * 64;
            y = cub->player.beg_y + sin(i) * 64;
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, cub->player.beg_x, cub->player.beg_y - 10, 0x00000000);
            draw_line(cub, cub->player.beg_x + 5, cub->player.beg_y, cub->player.beg_x + 5, cub->player.beg_y, 0x00ff0ff00);
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, x, y, 0x00ff0ff00);
            i += 0.15;
        }
        cub->player.rotaionagngle =cub->player.rotaionagngle +  0.15;
    }
    if (key == 13)
    {
        cub->c = 2;
        mlx_clear_window(cub->mlx, cub->window);
        white_window(cub);
        paint_wall(cub);
        cub->player.beg_x += cos(cub->player.rotaionagngle) * 64;
        cub->player.beg_y += sin(cub->player.rotaionagngle) * 64;

        double max_angle = FOV / 2;
        double i = cub->player.rotaionagngle - max_angle;
        while (i < cub->player.rotaionagngle + max_angle)
        {
            x = cub->player.beg_x + cos(i) * 64;
            y = cub->player.beg_y + sin(i) * 64;
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, x, y, 0x00ff0ff00);

            i += 0.15;
        }
    }
    if (key == 1)
    {
        cub->c = 2;
        mlx_clear_window(cub->mlx, cub->window);
        white_window(cub);
        paint_wall(cub);
        cub->player.beg_x -= cos(cub->player.rotaionagngle) * 64;
        cub->player.beg_y -= sin(cub->player.rotaionagngle) * 64;

        double max_angle = FOV / 2;
        double i = cub->player.rotaionagngle - max_angle;
        while (i < cub->player.rotaionagngle + max_angle)
        {
            x = cub->player.beg_x + cos(i) * 64;
            y = cub->player.beg_y + sin(i) * 64;
            draw_line(cub, cub->player.beg_x, cub->player.beg_y, x, y, 0x00ff0ff00);

            i += 0.15;
        }
    }
    if (key == 0)
    {
       // cub->c = 2;
        mlx_clear_window(cub->mlx, cub->window);
        white_window(cub);
        paint_wall(cub);
        cub->player.beg_x -= cos(cub->player.rotaionagngle) * 64;
        cub->player.beg_y -= sin(cub->player.rotaionagngle) * 64;

        double max_angle = FOV / 2;
        double i = cub->player.rotaionagngle - max_angle;
        while (i < cub->player.rotaionagngle + max_angle)
        {
            x = cub->player.beg_x - cos(i) * 64;
           y = cub->player.beg_y + sin(i) * 64;

            draw_line(cub, cub->player.beg_x, cub->player.beg_y, x, y, 0x00ff0ff00);

            i += 0.15;
        }


    }
    if (key == 53)
        exit(4);

    return 0;
}
*/

int move(int key ,t_cub *cub)
{
    return 0;
}
int main(int agrc, char **argv)
{
    t_cub *cub;
    if (agrc != 2)
        return 1;
    cub = ft_calloc(sizeof(t_cub), 1);
    cub->rgb_c = ft_calloc(sizeof(t_color), 1);
    cub->rgb_f = ft_calloc(sizeof(t_color), 1);
    check_map_valid(cub, argv[1]);
    cub->c = 0;
    cub->win_width = 15 * 64;
    cub->win_height = 6 * 64;
    cub->player.rotaionagngle = 0;

    cub->player.beg_x = cub->win_width / 2;
    cub->player.beg_y = cub->win_height / 2;

    cub->mlx = mlx_init();
    cub->window = mlx_new_window(cub->mlx, cub->win_width, cub->win_height, "cub3d");
    white_window(cub);
    paint_wall(cub);
    mlx_hook(cub->window, 2, 1L, move, cub);
    mlx_loop(cub->mlx);
    free_tab(cub->lines);
}

// rayangle = rangle - (fov / 2);

// while(i < 360)
// {
//     calulate_ray(ra)
//     data.rayabgle[i] = rayangle;
//     rayangle += fov / win_w;
// }
