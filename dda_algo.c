/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:24:00 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/01 17:18:56 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int ft_abs(int num)
{
    if(num < 0)
        num *= -1;
    return num; 
}
void put_pixels(t_data *data, const uint32_t  x, const uint32_t  y,  const uint32_t color) {
    if (x >= 0 && x < data->img->width && y >= 0 && y < data->img->height) {
        mlx_put_pixel(data->img, x, y, color);
    }
}

void draw_line_dda(t_data *data, const uint32_t x1, const uint32_t y1, const uint32_t x2, const uint32_t y2) {
    int dx = (int)x2 - (int)x1;
    int dy = (int)y2 - (int)y1;
    int steps;
    if(ft_abs(dx) >= ft_abs(dy)) 
        steps = ft_abs(dx);
    else 
        steps = ft_abs(dy);

    if (steps == 0) 
		return;

    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;    

    float x = x1;
    float y = y1;
    int i = 0;
    while ( i <= steps) {
        put_pixels(data, roundf(x), roundf(y), 0xFF0000FF);
        x += x_inc;
        y += y_inc;
        i++;
    }
}
