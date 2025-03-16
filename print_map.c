/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:40 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 02:53:44 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hirzontal(t_fdf *tab, int index_y, int index_x, t_data *data)
{
	t_line	line;

	if (index_x < tab->width - 1)
	{
		line.x1 = data->x1;
		line.y1 = data->y1;
		line.x2 = (index_x + 1) * tab->scale;
		line.y2 = index_y * tab->scale;
		line.z2 = tab->map[index_y][index_x + 1] * data->zoo;
		isometric(&line.x2, &line.y2, line.z2);
		line.x1 += tab->sclaing_x;
		line.y1 += tab->sclaing_y;
		line.x2 += tab->sclaing_x;
		line.y2 += tab->sclaing_y;
		draw_line_dda(data, line);
	}
}

void	ft_virtical(t_fdf *tab, int index_y, int index_x, t_data *data)
{
	t_line	line;

	if (index_y < tab->height - 1)
	{
		line.x1 = data->x1;
		line.y1 = data->y1;
		line.x2 = index_x * tab->scale;
		line.y2 = (index_y + 1) * tab->scale;
		line.z2 = tab->map[index_y + 1][index_x] * data->zoo;
		isometric(&line.x2, &line.y2, line.z2);
		line.x1 += tab->sclaing_x;
		line.y1 += tab->sclaing_y;
		line.x2 += tab->sclaing_x;
		line.y2 += tab->sclaing_y;
		draw_line_dda(data, line);
	}
}

void	ft_checksclae(t_fdf *tab, t_data *data, t_centre *cen)
{
	tab->scale = ft_scale(data, tab, cen);
	if (tab->scale < 10)
	{
		data->zoo = (tab->scale / 2);
	}
	else
		data->zoo = (tab->scale / 7);
}

void	print_map(t_fdf *tab, t_data *data, t_centre *cen)
{
	int	index_y;
	int	index_x;

	ft_checksclae(tab, data, cen);
	index_y = 0;
	while (index_y < tab->height)
	{
		index_x = 0;
		while (index_x < tab->width)
		{
			data->x1 = index_x * tab->scale;
			data->y1 = index_y * tab->scale;
			data->z1 = tab->map[index_y][index_x] * data->zoo;
			isometric(&data->x1, &data->y1, data->z1);
			ft_hirzontal(tab, index_y, index_x, data);
			ft_virtical(tab, index_y, index_x, data);
			index_x++;
		}
		index_y++;
	}
}
