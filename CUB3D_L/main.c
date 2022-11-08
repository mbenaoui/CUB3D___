#include "include/cub3d.h"
#include <stdbool.h>
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

int move_t(int key, t_cub *cub)
{
    if (key == UP_W)
        cub->player.walkDirection = 0;
    if (key == DOWN_S)
        cub->player.walkDirection = 0;
    if (key == UP_A)
        cub->player.walk_side_Direction = 0;
    if (key == UP_D)
        cub->player.walk_side_Direction = 0;
    // if (key == RIGHT_ARR)
    //     cub->player.rotaionagngle += cub->player.rotaionaSpeed;
    // if (key == LEFT_ARR)
    //     cub->player.rotaionagngle -= cub->player.rotaionaSpeed;
    return 0;
}

int hasWallat(double x, double y, t_cub *cub)
{
    if (x < 0 || x > cub->win_width || y < 0 || y > cub->win_height)
        return 1;
    int mapGrindIndexX = x / 64;
    int mapGrindIndexY = y / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] != '1')
        return 0;
    return (1);
}

double fix_angle(double angle)
{
    if(angle >= 2 * M_PI)
        angle = 0;
    if(angle < 0)
        angle = 2 * M_PI;
    return angle;
}
double distanceBetweenPoints( x1, y1, x2, y2 )
{
    return sqrt((x2 - x1) *(x2 - x1) + (y2 - y1) *(y2 - y1));
}
void distancehorz( double rayangle, t_cub *cub)
{
            double wallHiitx = 0;
        double wallHiity = 0;
        double distance = 0;
        cub->foundHorzWallHit = 0;
        bool isRayFacingDOwn = rayangle > 0 && rayangle < M_PI;
        bool isRayFacingUp = !isRayFacingDOwn;
        bool isRayFacingRight = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
        bool isRayFacingLeft = !isRayFacingRight;

        double xintercept, yintercept;
        double xstep, ystep;

        yintercept = floor((cub->player.beg_y / 64)) * 64;
        yintercept += isRayFacingDOwn ? 64 : 0;
        xintercept = cub->player.beg_x + ((yintercept - cub->player.beg_y) / tan(rayangle));
        ystep = 64;
        ystep *= isRayFacingUp ? -1 : 1;

        xstep = ystep / tan(rayangle);
        xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
        xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;
        double nextHorzToouchX = xintercept;
        double nextHorzToouchY = yintercept;
        if (isRayFacingUp)
            nextHorzToouchY--;
        // printf("|%f|\n", nextHorzToouchY);
        // printf("|%d|\n",  cub->win_height);
        // sleep(1);
        // exit(1);
        while (nextHorzToouchX >= 0 && nextHorzToouchX <= cub->win_width && nextHorzToouchY >= 0 && nextHorzToouchY <= cub->win_height)
        {
            if (hasWallat(nextHorzToouchX, nextHorzToouchY, cub))
            {
                  cub->foundHorzWallHit = 1;
                cub->horzWallHitX = nextHorzToouchX;
                cub->horzWallHitY = nextHorzToouchY + 1;
                break;
            }
            else
            {
                nextHorzToouchX += xstep;
                nextHorzToouchY += ystep;
            }
        }
}
void distancevert( double rayangle, t_cub *cub)
{
            double wallHiitx = 0;
        double wallHiity = 0;
        double distance = 0;
        cub->foundVertWallHit = 0;
        bool isRayFacingDOwn = rayangle > 0 && rayangle < M_PI;
        bool isRayFacingUp = !isRayFacingDOwn;
        bool isRayFacingRight = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
        bool isRayFacingLeft = !isRayFacingRight;

        double xintercept, yintercept;
        double xstep, ystep;

        xintercept = floor((cub->player.beg_x / 64)) * 64;
        xintercept += isRayFacingRight ? 64 : 0;
        yintercept = cub->player.beg_y + (xintercept - cub->player.beg_x)  * tan(rayangle);
        xstep = 64;
        xstep *= isRayFacingLeft ? -1 : 1;

        ystep = xstep *tan(rayangle);
        ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
        ystep *= (isRayFacingDOwn && ystep < 0) ? -1 : 1;
        double nextHorzToouchX = xintercept;
        double nextHorzToouchY = yintercept;
        if (isRayFacingLeft)
            nextHorzToouchX--;
        // printf("|%f|\n", nextHorzToouchY);
        // printf("|%d|\n",  cub->win_height);
        // sleep(1);
        // exit(1);
        while (nextHorzToouchX >= 0 && nextHorzToouchX <= cub->win_width && nextHorzToouchY >= 0 && nextHorzToouchY <= cub->win_height)
        {
            if (hasWallat(nextHorzToouchX, nextHorzToouchY, cub))
            {
                cub->foundVertWallHit = 1;
                cub->vertWallHitX = nextHorzToouchX + 1;
                cub->vertWallHitY = nextHorzToouchY;
                break;
            }
            else
            {
                nextHorzToouchX += xstep;
                nextHorzToouchY += ystep;
            }
        }
}
int move(int key, t_cub *cub)
{

    // printf("hoow\n");
    double move_speed = 2.0;
    double move_step_x;
    double move_step_y;
    if (key == UP_W)
        cub->player.walkDirection = MOVE;
    if (key == DOWN_S)
        cub->player.walkDirection = -MOVE;
    if (key == UP_A)
        cub->player.walk_side_Direction = MOVE;
    if (key == UP_D)
        cub->player.walk_side_Direction = -MOVE;
    if (key == RIGHT_ARR)
        cub->player.rotaionagngle += cub->player.rotaionaSpeed;
    if (key == LEFT_ARR)
        cub->player.rotaionagngle -= cub->player.rotaionaSpeed;

    cub->player.rotaionagngle = fix_angle(cub->player.rotaionagngle);
    move_step_x = cub->player.walkDirection;
    move_step_y = cub->player.walk_side_Direction;

    double nextx = round(cub->player.beg_x + (cos(cub->player.rotaionagngle) * move_step_x + sin(cub->player.rotaionagngle) * move_step_y));
    double nexty =round(cub->player.beg_y + (sin(cub->player.rotaionagngle) * move_step_x - cos(cub->player.rotaionagngle) * move_step_y));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!hasWallat(nextx, nexty, cub))
    {
        cub->player.beg_x = nextx;
        cub->player.beg_y = nexty;
    }

    mlx_clear_window(cub->mlx, cub->window);
    white_window(cub);
    paint_wall(cub);
    // double i = 0;
    // if (cub->player.rotaionagngle < -2 * M_PI)
    //     cub->player.rotaionagngle += 2 * M_PI;
    // if (cub->player.rotaionagngle > 2 * M_PI)
    //     cub->player.rotaionagngle -= 2 * M_PI;

    // // printf("\n(%f)\n", (cub->player.rotaionagngle) * 180 / M_PI);
    // int flag;
    // if (cub->player.rotaionagngle < M_PI_2 && cub->player.rotaionagngle >= 0)
    //     flag = 0;
    // if (cub->player.rotaionagngle < M_PI && cub->player.rotaionagngle >= M_PI_2)
    //     flag = 1;
    // if (cub->player.rotaionagngle < 3 * M_PI_2 && cub->player.rotaionagngle >= M_PI)
    //     flag = 2;
    // if (cub->player.rotaionagngle < 2 * M_PI && cub->player.rotaionagngle >= 3 * M_PI_2)
    //     flag = 3;

    // double ferstintrX = cub->player.beg_x - ((int)cub->player.beg_x / 64) * 64;
    // double ferstintrY = cub->player.beg_y - ((int)cub->player.beg_y / 64) * 64;

    // if(flag  == 0)
    // {
    //     ferstintrX = 64 - ferstintrX;
    //     ferstintrY = 64 - ferstintrY;
    // }
    // else if(flag == 1)
    //     ferstintrY = 64 - ferstintrY;
    // else if(flag == 2);
    // else if(flag == 3)
    //     ferstintrX = 64 - ferstintrX;
    // printf("%f | %f\n", ferstintrX,ferstintrY);

    // double Ax = 64 - x;
    // double Ay = Ax * tan(cub->player.rotaionagngle);
    // double By = y;
    // double Bx = By / tan(cub->player.rotaionagngle);

    // double stpXx = 64;
    // double stpXy = 64 * tan(cub->player.rotaionagngle);

    // double stpYx = 64;
    // double stpYy = 64 / tan(cub->player.rotaionagngle);

    // double wallx =  ferstintrX;
    // double wally =  ferstintrY;

    // while (1)
    // {
    //     if (flag == 0)
    //     {
    //         // wallx +=
    //     }
    // }

    // printf("%f | %f )(%f | %f\n", x, y, stpx, stpy);

    double rayangle = cub->player.rotaionagngle - (FOV / 2);

    for (int i = 0; i < 320; i++)
    {
        rayangle = fix_angle(rayangle);
        double wallHiitx = 0;
        double wallHiity = 0;
        double distance = 0;
        distancehorz(rayangle, cub);
        distancevert(rayangle, cub);
        double horzHitDistance = cub->foundHorzWallHit 
        ? distanceBetweenPoints(cub->player.beg_x, cub->player.beg_y, cub->horzWallHitX, cub->horzWallHitY) :INT_MAX;
        double vertHitDistance = cub->foundVertWallHit
        ? distanceBetweenPoints(cub->player.beg_x, cub->player.beg_y, cub->vertWallHitX, cub->vertWallHitY) :INT_MAX;
        wallHiitx = (horzHitDistance < vertHitDistance) ? cub->horzWallHitX : cub->vertWallHitX;
        wallHiity = (horzHitDistance < vertHitDistance)? cub->horzWallHitY : cub->vertWallHitY;
            draw_line(cub, cub->player.beg_x, cub->player.beg_y,wallHiitx,
                  wallHiity, 0x00000000);
        rayangle += FOV / WIN_W;

    }
    if (key == 53)
        exit(4);
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
    cub->win_width = 15 * 64;
    cub->win_height = 6 * 64;
    cub->player.rotaionagngle = (M_PI / 2);
    cub->player.rotaionaSpeed = 5 * (M_PI / 180);
    cub->player.beg_x = cub->win_width / 2;
    cub->player.beg_y = cub->win_height / 2;

    cub->player.end_x = cub->win_width / 2;
    cub->player.end_y = 0;
    cub->mlx = mlx_init();
    cub->window = mlx_new_window(cub->mlx, cub->win_width, cub->win_height, "cub3d");

    white_window(cub);
    paint_wall(cub);
    mlx_hook(cub->window, 2, 1L, move, cub);
    mlx_hook(cub->window, 3, 1L << 1, move_t, cub);
    mlx_loop(cub->mlx);
    free_tab(cub->lines);

    return 0;
}
