/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:40 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/15 03:41:08 by bsalim           ###   ########.fr       */
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

void	print_map(t_fdf *tab, t_data *data,t_centre *cen)
{
    int index_y = 0 ;
    int index_x = 0;
	tab->SCALE = ft_scale(data,tab,cen);
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
