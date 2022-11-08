#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "mlx.h"
#include  <math.h>

#define FOV 1.0472
#define INC_FOV 0.0174533333
#define WIN_W 320;
#define WIN_H 670;
typedef struct t_var
{
    int i;
    int j;
    int k;
    int len;
    int x;
    int y;
    char *str; 
    char *dst;   
    char **tab;
}t_var;
typedef struct s_color
{
    int _r;
    int _g;
    int _b;
}t_color;

typedef struct s_player
{
    int beg_x;
    int beg_y;
    int end_x;
    int end_y;
    double rotaionagngle;
}t_player;

typedef struct s_cub3d
{
    char **map;
    char **lines;
    char *fd_so;
    char *fd_no;
    char *fd_we;
    char *fd_ea;
    char *before_map;
    int size1;
    int size2;
    t_color *rgb_f;
    t_color *rgb_c;
    t_player player;
    char *mlx;
    int c;
    int _check_end_y;
    int win_height;
    int win_width;
    char *window;
}t_cub;

int main(int argc, char **argv);
void check_map_valid(t_cub *cub, char *path);
int	ft_strcmp(char *s1, char *s2);
void msg_error(int status);
int size_map(char *path);
void free_tab(char **tab);
int handling_texture(t_cub *cub, int i, int j);
void search_color(t_cub *cub, char *str, int *j, int index);
void handling_color(t_cub *cub, char *des, int index, int i);
void check_color(t_var var);
int len_tab(char **tab, int index);
int handling_texture(t_cub *cub, int i, int j);
void handling_texture_2(char **str, int *j, t_cub *cub, int i);
void print_info(char *str, int n);
void check_may_map(char **map, int i, int j, int k);
int if_player(char c);
void draw_line(t_cub *cub, int beginX, int beginY, int endX, int endY, int color);
void white_window(t_cub *cub);
void paint_wall(t_cub *cub);
#endif