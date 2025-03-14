/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:40 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/14 02:06:43 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define BASE_SCALE 30
void	ft_hirzontal(t_fdf *tab, int index_y, int index_x, t_data *data,int zoo)
{
	if (index_x < tab->width - 1)
	{
		data->x2 = (index_x + 1) * tab->SCALE     ;
		data->y2 = index_y * tab->SCALE    ;
		data->z2 = tab->map[index_y][index_x + 1] * zoo;
		isometric(&data->x2, &data->y2, data->z2);
		draw_line_dda(data, (data->x1 + tab->sclaing_x ), (data->y1 + tab->sclaing_y  ), (data->x2  + tab->sclaing_x ), (data->y2 + tab->sclaing_y ));
	}
	
}

void	ft_virtical(t_fdf *tab, int index_y, int index_x, t_data *data,int zoo)
{
		if (index_y < tab->height - 1)
		{
		data->x2 = index_x * tab->SCALE  ;
		data->y2 = (index_y + 1) * tab->SCALE   ;
		data->z2 = tab->map[index_y + 1][index_x] * zoo;
		isometric(&data->x2, &data->y2, data->z2);
		draw_line_dda(data, (data->x1 + tab->sclaing_x ), (data->y1 + tab->sclaing_y  ), (data->x2  + tab->sclaing_x ), (data->y2 + tab->sclaing_y ));
		}
}

#define max(a,b) ((a) > (b)) ? (a) : (b)

#define min(a,b) ((a) < (b)) ? (a) : (b)
float ft_scale(t_data *data, t_fdf *tab)
{
    float scale_factor = min(
        ((float)data->img->width) / ((float)tab->width * 2),
        ((float)data->img->height) / ((float)tab->height * 2)
    );
    
    if(scale_factor > 30)
        scale_factor = 30;
    else if(scale_factor < 2)
        scale_factor = 2;
    
    float max_x = 0, min_x = 0, max_y = 0, min_y = 0;
    int y= 0;
    while(y < tab->height) 
	{
		int x = 0;
        while(x < tab->width ) {
            float px = x * scale_factor;
            float py = y * scale_factor;
            float pz = tab->map[y][x] * (scale_factor / 8); 
            
            float iso_x, iso_y;
            iso_x = px - py;
            iso_y = (px + py) / 2 - pz;
            
            if(x == 0 && y == 0) {
                min_x = max_x = iso_x;
                min_y = max_y = iso_y;
            } else {
                min_x = min(min_x, iso_x);
                max_x = max(max_x, iso_x);
                min_y = min(min_y, iso_y);
                max_y = max(max_y, iso_y);
            }
			x++;
        }
		y++;
    }
    
    float width = max_x - min_x;
    float height = max_y - min_y;
    
    tab->sclaing_x = (data->img->width - width) / 2 - min_x;
    tab->sclaing_y = (data->img->height - height) / 2 - min_y;
    
    return scale_factor;
}void	print_map(t_fdf *tab, t_data *data)
{
    int index_y = 0 ;
    int index_x = 0;
	tab->SCALE = ft_scale(data,tab);
	int zoo;
	if(tab->SCALE < 10)
	{
		zoo = (tab->SCALE / 2);
	}
	else  
		zoo =  (tab->SCALE / 8);
	printf("%d",tab->SCALE);

	index_y = 0;
	while (index_y < tab->height)
	{
		index_x = 0;
		while (index_x < tab->width)
		{
			data->x1 = index_x * tab->SCALE ;
			data->y1 = index_y * tab->SCALE  ;
			data->z1 = tab->map[index_y][index_x] * zoo;
			isometric(&data->x1, &data->y1, data->z1);
			ft_hirzontal(tab, index_y, index_x, data,zoo);
			ft_virtical(tab, index_y, index_x, data,zoo);	
			index_x++;
		}
		index_y++;
	}
}
