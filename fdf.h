# ifndef  FDF_H
# define FDF_H  
#include "./MLX/include/MLX42/MLX42.h"
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)

typedef struct s_data {
    mlx_t *mlx;
    mlx_image_t *img;
	int x1;
    int y1;
    
    int z1;
	int x2;
    int y2;
    int z2;
} t_data;
typedef struct s_fdf {
	int **map;
	char **av;
	 int height;
	 int width;
    int SCALE;
    float sclaing_x;
    float sclaing_y;
    int colors;
    
    
} t_fdf;
typedef struct s_center
{
	float max_x , min_x , max_y , min_y ;
	float iso_x, iso_y;
	float px;
	float py;
	float scale_factor;
	float pz;
	float width ;
	float height ;
} t_centre;


#define BASE_SCALE 30
#define MIN_SCALE 2
#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) < (b)) ? (a) : (b)
void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
void put_pixels(t_data *data,  const uint32_t x,  const uint32_t y,const uint32_t color);
int get_width(t_fdf *tab);
void read_file(t_fdf *tab);
void isometric(int *x , int *y , int z);
int	get_height(t_fdf *tab);
void ft_free(char **arr);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *string);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void draw_line_dda(t_data *data,  int32_t x1,  int32_t y1,  int32_t x2,  int32_t y2);
mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height);
void mlx_loop(mlx_t* mlx);
void mlx_terminate(mlx_t* mlx);
void key_hook(mlx_key_data_t key, void *p);
float ft_scale(t_data *data, t_fdf *tab,t_centre *cen);
void	print_map(t_fdf *tab, t_data *data,t_centre *cen);


#endif