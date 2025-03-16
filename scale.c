/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:00:01 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 01:21:02 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_withd(t_centre *cen, int x, int y)
{
    if (x == 0 && y == 0)
    {
        cen->min_x = cen->max_x = cen->iso_x;
        cen->min_y = cen->max_y = cen->iso_y;
    } 
    else 
    {
        cen->min_x = ft_min(cen->min_x, cen->iso_x);
        cen->max_x = ft_max(cen->max_x, cen->iso_x);
        cen->min_y = ft_min(cen->min_y, cen->iso_y);
        cen->max_y = ft_max(cen->max_y, cen->iso_y);
    }
}

void ft_centre(t_fdf *tab,t_centre *cen)
{
    int	y;
	int	x;

    y = 0;
    while(y < tab->height) 
	{
		x = 0;
        while(x < tab->width ) {
            cen->px = x * cen->scale_factor;
            cen->py = y * cen->scale_factor;
            cen->pz = tab->map[y][x] * (cen->scale_factor / 8); 
            cen->iso_x = cen->px - cen->py;
            cen->iso_y = (cen->px + cen->py) / 2 - cen->pz;
            scale_withd(cen, x, y);
			x++;
        }
		y++;
    }
}

float ft_scale(t_data *data, t_fdf *tab,t_centre *cen)
{
    cen->scale_factor = ft_min(
        ((float)data->img->width) / ((float)tab->width * 3),
        ((float)data->img->height) / ((float)tab->height * 3)
    );
    if(cen->scale_factor > BASE_SCALE)
        cen->scale_factor = BASE_SCALE;
    else if(cen->scale_factor < MIN_SCALE)
        cen->scale_factor = MIN_SCALE;
    ft_centre(tab,cen);
    cen->width = cen->max_x - cen->min_x;
    cen->height = cen->max_y - cen->min_y;
    tab->sclaing_x = (data->img->width - cen->width) / 2 - cen->min_x;
    tab->sclaing_y = (data->img->height - cen->height) / 2 - cen->min_y;
    return cen->scale_factor;
}
