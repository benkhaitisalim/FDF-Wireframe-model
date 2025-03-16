/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:24:00 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 01:32:56 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixels(t_data *data, const uint32_t x,
	const uint32_t y, const uint32_t color)
{
	if (x < data->img->width && y < data->img->height)
		mlx_put_pixel (data->img, x, y, color);
}

void	draw_line_dda(t_data *data, t_line line)
{
	int	i;

	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	if (ft_abs(line.dx) >= ft_abs(line.dy)) 
		line.steps = ft_abs(line.dx);
	else 
		line.steps = ft_abs(line.dy);
	if ((line.dx == 0 && line.dy == 0) || line.steps == 0)
		return ;
	line.x_inc = (float)line.dx / line.steps;
	line.y_inc = (float)line.dy / line.steps;
	line.x = line.x1;
	line.y = line.y1;
	i = 0;
	while (i <= line.steps) 
	{
		put_pixels(data, line.x, line.y, 0xFF0000FF);
		line.x += line.x_inc;
		line.y += line.y_inc;
		i++;
	}
}
