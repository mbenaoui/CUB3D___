#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
double posX, posY;
double dirX, dirY;
double planX, planY;
char *mlx;
char *window;
double rotSpeed;
double moveSpeed;
#define UP_W 13
#define DOWN_S 1
#define UP_A 0
#define UP_D 2
#define LEFT_ARR 123
#define RIGHT_ARR 124
#define MOVE 1
double walk_side_Direction;
double walkDirection;
double rotaionagngle;
#define rotaionaSpeed 2 * (M_PI / 180)
int a[2];
int worldMap[mapWidth][mapHeight] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void draw_line(int beginX, int beginY, int endX, int endY, int color)
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
        mlx_pixel_put(mlx, window, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

int move(int key, char *ptr)
{

    if (key == 1 || key == 13 || key == 0 || key == 2 || key == 123 || key == 124)
    {
        rotSpeed = 0.2;
        moveSpeed = 0.3;
        //     cub->player.walkDirection = MOVE;
        // if (key == DOWN_S)
        //     cub->player.walkDirection = -MOVE;
        if (key == UP_A)
        {
            if (worldMap[(int)(posX - planX * moveSpeed)][(int)posY] == 0)
                posX -= planX  * moveSpeed;
            if (worldMap[(int)posX][(int)(posY - planY * moveSpeed)] == 0)
                posY -= planY * moveSpeed;
        }
        if (key == UP_D)
        {
              if (worldMap[(int)(posX + planX * moveSpeed)][(int)posY] == 0)
                posX += planX  * moveSpeed;
            if (worldMap[(int)posX][(int)(posY + planY  * moveSpeed)] == 0)
                posY += planY * moveSpeed;
        }
    
        // if (key == RIGHT_ARR)
        // {
        //     cub->player.rotaionagngle += cub->player.rotaionaSpeed;
        // }
        // if (key == LEFT_ARR)
        //     cub->player.rotaionagngle -= cub->player.rotaionaSpeed;
        // /////////////////////////////
        // move_step_x  =  cub->player.walkDirection * move_speed;
        // move_step_y  =  cub->player.walk_side_Direction * move_speed;
        //  cub->player.beg_x += round (cos(cub->player.rotaionagngle) * move_step_x + sin(cub->player.rotaionagngle) * move_step_y);
        //  cub->player.beg_y += round (sin(cub->player.rotaionagngle) * move_step_x - cos(cub->player.rotaionagngle) * move_step_y);
        //     if (key == UP_W)
        if (key == UP_W)
        {
            if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
                posX += dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
                posY += dirY * moveSpeed;
        }
        if (key == DOWN_S)
        {
            if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
                posX -= dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
                posY -= dirY * moveSpeed;
        }

        if (key == 123)
        {
            // both camera direction and camera plane must be rotated
            double oldDirX = dirX;
            dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
            dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
            double oldPlaneX = planX;
            planX = planX * cos(-rotSpeed) - planY * sin(-rotSpeed);
            planY = oldPlaneX * sin(-rotSpeed) + planY * cos(-rotSpeed);
        }
        if (key == 124)
        {
            // both camera direction and camera plane must be rotated
            double oldDirX = dirX;
            dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
            dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
            double oldPlaneX = planX;
            planX = planX * cos(rotSpeed) - planY * sin(rotSpeed);
            planY = oldPlaneX * sin(rotSpeed) + planY * cos(rotSpeed);
        }
        mlx_clear_window(mlx, window);
        for (int x = 0; x < screenWidth; x++)
        {
            // calculate ray position and direction
            double cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space

            double rayDirX = dirX + planX * cameraX;
            double rayDirY = dirY + planY * cameraX;
            // which box of the map we're in
            int mapX = (int)posX;
            int mapY = (int)posY;

            // length of ray from current position to next x or y-side
            double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

            // deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            // deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

            double perpWallDist;
            // what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; // was there a wall hit?
            int side;    // was a NS or a EW wall hit?
            // calculate step and initial sideDist
            double sideDistX;
            double sideDistY;
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }

            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }
            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                if (worldMap[mapX][mapY] > 0)
                    hit = 1;
            }
            if (side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);
            int lineHeight = (int)(screenHeight / perpWallDist);
            int drawStart = -lineHeight / 2 + screenHeight / 2;
            if (drawStart < 0)
                drawStart = 0;
            int drawEnd = lineHeight / 2 + screenHeight / 2;
            if (drawEnd >= screenHeight)
                drawEnd = screenHeight - 1;
            int color;
            switch (worldMap[mapX][mapY])
            {
            case 1:
                color = 0x00ff0ff00 / 2;
                break; // red
            case 2:
                color = 0x00ff0ff00 / 4;
                break; // green
            case 3:
                color = 0x00ff0ff00 / 8;
                break; // blue
            case 4:
                color = 0x00ff0ff00 / 16;
                break; // white
            default:
                color = 0x00ff0ff00;
                break; // yellow
            }
            if (side == 1)
            {
                color = color / 2;
            }
            draw_line(x, drawStart, x, drawEnd, color);
        }
    }
    if (key == 53)
        exit(0);

    return 0;
}
int main()
{
    a[0] = 0;
    a[1] = 0;
    posX = 4;
    posY = 12;
    rotSpeed = 1;
    moveSpeed = 0;
    dirX = 1;
    dirY = 0;

    planX = 0;
    planY = 0.66;
    rotaionagngle = M_PI_2;
    mlx = mlx_init();
    window = mlx_new_window(mlx, screenWidth, screenHeight, "cub3d");
    mlx_hook(window, 2, 1L, move, NULL);
    // draw_line(posX, posY, posX * dirX, posY * dirY, 0x00ff0ff00);
    mlx_loop(mlx);
}
