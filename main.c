/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:29:55 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/02 02:44:27 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
int	main(int ac, char **av)
{
	t_data	data;
	t_fdf	tab;

	if (ac == 2)
	{
		tab.av = av; 
		data.mlx = mlx_init(1920, 1080, "DDA TEST", true);
		if (!data.mlx) 
			return (1);
		data.img = mlx_new_image(data.mlx, 1920, 1080); 
		if (!data.img) 
		{
			mlx_terminate (data.mlx);
			return (1);
		}
		mlx_image_to_window(data.mlx, data.img, 0, 0);
		read_file(&tab);
		print_map(&tab, &data);
		mlx_loop(data.mlx);
		mlx_delete_image(data.mlx, data.img);
		mlx_terminate(data.mlx);
		return (0);
	}
	printf("error dir ghir arrg wahda \n");
}
