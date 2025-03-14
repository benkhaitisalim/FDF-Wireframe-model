/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:24:00 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/08 15:42:15 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void put_pixels(t_data *data, const uint32_t  x, const uint32_t  y,  const uint32_t color) {
    if (x >= 0 && x < data->img->width && y >= 0 && y < data->img->height) {
        mlx_put_pixel(data->img, x, y, color);
    }
}

void draw_line_dda(t_data *data,  int32_t x1,  int32_t y1,  int32_t x2,  int32_t y2) {
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    int32_t steps;
    if(abs(dx) >= abs(dy)) 
        steps = abs(dx);
    else 
        steps = abs(dy);
    if((dx == 0 &&  dy == 0)|| steps == 0)
        return;
    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;    
    float x = x1;
    float y = y1;
    int i = 0;
    while ( i <= steps) {
        put_pixels(data, x, y,0xFF0000FF);
        x += x_inc;
        y += y_inc;
        i++;
    }
}