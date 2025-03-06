/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:40 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/06 00:30:30 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define H 1920
#define W 1080
#define BASE_SCALE 30
void	ft_lkhtisarat(t_fdf *tab, int index_y, int index_x, t_data *data, int offset_x,int offset_y,int SCALE)
{
		data->x1 = index_x * SCALE;
		data->y1 = index_y * SCALE;
		data->z1 = tab->map[index_y][index_x] * (SCALE / 8);
		data->x2 = (index_x + 1) * SCALE;
		data->y2 = index_y * SCALE;
		data->z2 = tab->map[index_y][index_x + 1] * (SCALE / 8);
		isometric(&data->x1, &data->y1, data->z1);
		isometric(&data->x2, &data->y2, data->z2);
		draw_line_dda(data, (data->x1 + offset_x)  , (data->y1 + offset_y),
			(data->x2 + offset_x) , (data->y2 + offset_y) );
}

void	ft_lkhtisarat2(t_fdf *tab, int index_y, int index_x, t_data *data,int offset_x,int offset_y,int  SCALE)
{
		data->x1 = index_x * SCALE;
		data->y1 = index_y * SCALE;
		data->z1 = tab->map[index_y][index_x] * (SCALE / 8);
		data->x2 = index_x * SCALE;
		data->y2 = (index_y + 1) * SCALE;
		data->z2 = tab->map[index_y + 1][index_x] * (SCALE / 8);
		isometric(&data->x1, &data->y1, data->z1);
		isometric(&data->x2, &data->y2, data->z2);
		draw_line_dda(data, (data->x1 + offset_x) , (data->y1 + offset_y),
			(data->x2 + offset_x) , (data->y2 + offset_y));
}
int ft_scale_calcule(t_fdf *tab)
{
	int max_dimension;
	int SCALE ;
	if(tab->width > tab->height)
		max_dimension = tab->width;
	else
		max_dimension = tab->height;
	if(max_dimension > 20) 
	  SCALE =(BASE_SCALE * 20) / max_dimension;
	else 
		SCALE = BASE_SCALE;
	return SCALE;
}
void	print_map(t_fdf *tab, t_data *data)
{
	int	index_y;
	int	index_x;
	index_y = 0;
	int SCALE = ft_scale_calcule(tab);
	int offset_x = (H - (tab->width * SCALE)) / 2;
	int offset_y = (W - (tab->height * SCALE)) / 2;

	while (index_y < tab->height)
	{
		index_x = 0;
		while (index_x < tab->width)
		{
			if (index_x < tab->width - 1)
			{
				ft_lkhtisarat(tab, index_y, index_x, data,offset_x,offset_y,SCALE);
			}
			if (index_y < tab->height - 1)
			{
				ft_lkhtisarat2(tab, index_y, index_x, data,offset_x,offset_y,SCALE);
			}
			index_x++;
		}
		index_y++;
	}
}
