/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:53:03 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 05:52:17 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include "/Users/bsalim/MLX/include/MLX42/MLX42.h"
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include <math.h>
# include "libft/libft.h"
# define BASE_SCALE 30
# define MIN_SCALE 2

typedef struct s_line
{
	int32_t		x1;
	int32_t		y1;
	int32_t		x2;
	int32_t		y2;
	int32_t		z1;
	int32_t		z2;
	int32_t		dx;
	int32_t		dy;
	int32_t		steps;
	uint32_t	color;
	float		x_inc;
	float		y_inc;
	float		y;
	float		x;
}	t_line;
typedef struct s_aloc
{
		char	*str;
	char	**s_str;
	int		fd;
	int		index1;
	int		index2;

} t_aloc;
typedef struct s_data {
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x1;
	int			y1;
	char		*valid;
	int			zoo;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
}	t_data;

typedef struct s_fdf {
	int		**map;
	char	**av;
	int		height;
	int		width;
	int		scale;
	float	sclaing_x;
	float	sclaing_y;
	int		colors;
}	t_fdf;

typedef struct s_center
{
	float	max_x;
	float	min_x;
	float	max_y;
	float	min_y;
	float	iso_x; 
	float	iso_y;
	float	px;
	float	py;
	float	scale_factor;
	float	pz;
	float	width ;
	float	height ;
}	t_centre;
int				ft_strcmp(char *str, char *str2);
int				ft_error(t_data *data);
int				ft_abs(int num);
void			ft_check_file(char *valid, char **av);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			mlx_key_hook(mlx_t *mlx, mlx_keyfunc func, void *param);
void			put_pixels(t_data *data, const uint32_t x,
					const uint32_t y, const uint32_t color);
void			mlx_put_pixel(mlx_image_t *image,
					uint32_t x, uint32_t y, uint32_t color);
void			read_file(t_fdf *tab);
void			isometric(int *x, int *y, int z);
void			ft_free(char **arr);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *string);
char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *str);
void			draw_line_dda(t_data *data, t_line line);
mlx_image_t		*mlx_new_image(mlx_t *mlx, uint32_t width, uint32_t height);
void			mlx_loop(mlx_t *mlx);
void			mlx_terminate(mlx_t *mlx);
void			key_hook(mlx_key_data_t key, void *p);
float			ft_scale(t_data *data, t_fdf *tab, t_centre *cen);
void			print_map(t_fdf *tab, t_data *data, t_centre *cen);
int	**allocation_for_map(t_fdf *tab);
int	get_width(t_fdf *tab);
int	get_height(t_fdf *tab);

#endif