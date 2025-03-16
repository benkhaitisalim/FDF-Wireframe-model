/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:55:19 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 02:59:35 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(mlx_key_data_t key, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_ESCAPE)
			ft_error(data);
	}
}
