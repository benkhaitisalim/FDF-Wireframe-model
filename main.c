/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:29:55 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 05:15:39 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_fdf		tab;
	t_centre	cen;

	if (ac == 2)
	{
		system("leaks fdf");
		tab.av = av;
		data.valid = NULL;
		ft_check_file(data.valid, av);
		data.mlx = mlx_init(1920, 1080, "DDA TEST", true);
		data.img = mlx_new_image(data.mlx, 1920, 1080); 
		if (!data.img || !data.mlx)
			ft_error(&data);
		mlx_image_to_window(data.mlx, data.img, 0, 0);
		read_file(&tab);
		print_map(&tab, &data, &cen);
		mlx_key_hook(data.mlx, &key_hook, &data);
		mlx_loop(data.mlx);
		mlx_delete_image(data.mlx, data.img);
		mlx_terminate(data.mlx);
		return (0);
	}
	else
		ft_error(&data);
}
