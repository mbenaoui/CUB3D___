#include "../include/cub3d.h"

void paint_wall(t_cub *cub)
{
    int i, j;
    i = 0;
    j = 0;
    char *str;
    char **av = cub->map;
    str = mlx_xpm_file_to_image(cub->mlx, "/Users/mbenaoui/Desktop/Cub3d_badr/walll.xpm", &i, &j);
    i = 0;
    j = 0;

    while (cub->map[i])
    {
        j = 0;
        while (cub->map[i][j])
        {
            //if (cub->map[i][j] == '1')
                mlx_put_image_to_window(cub->mlx, cub->window, str, j * 64, i * 64);
            j++;
            // if (cub->map[i][j] == 'W')
            // {
            //     cub->player.beg_x = j * 64 + 32;
            //     cub->player.beg_y = i * 64;
            //     printf("%d | %d\n", cub->player.beg_x, cub->player.beg_y);
            // }
        }
        i++;
    }
}

void white_window(t_cub *cub)
{

    int i, j, k;
    i = 0;

    while (i < cub->win_width)
    {
        j = 0;
        while (j < cub->win_height)
        {
            mlx_pixel_put(cub->mlx, cub->window, i, j, 0x00ffffff);
            // mlx_pixel_put(cub->mlx, cub->window, i, j, 0x0f0ff000);
            j++;
        }
        i++;
    }
}


void draw_line(t_cub *cub, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;                            // 10
    double deltaY = endY - beginY;                            // 5
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY)); // 11.1
    deltaX /= pixels;                                         // 0
    deltaY /= pixels;                                         // 0
    double pixelX = beginX;                                   // 10
    double pixelY = beginY;                                   // 5
    while (pixels)
    {
        // dark_window(cub);
        mlx_pixel_put(cub->mlx, cub->window, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}
