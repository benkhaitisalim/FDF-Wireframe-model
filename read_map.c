/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:26:14 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 05:52:42 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reading(t_fdf *tab, t_aloc	aloc)
{

		aloc.index1 = 0;
	while (aloc.str && aloc.index1 < tab->height)
	{
		aloc.index2 = 0;
		aloc.s_str = ft_split(aloc.str, ' ');
		while (aloc.s_str[aloc.index2] && aloc.index2 < tab->width)
		{
			tab->map[aloc.index1][aloc.index2] = ft_atoi
				(aloc.s_str[aloc.index2]);
			aloc.index2++;
		}
		ft_free(aloc.s_str);
		free(aloc.str);
		aloc.str = get_next_line(aloc.fd);
		aloc.index1++;
	}
}

void	read_file(t_fdf *tab)
{
	t_aloc	aloc;

	aloc.fd = open(tab->av[1], O_RDONLY);
	aloc.str = get_next_line(aloc.fd);
	tab->map = allocation_for_map(tab);
	if (aloc.fd == -1 || !aloc.str || !tab->map || !aloc.str)
	{
		close(aloc.fd);
		free(aloc.str);
		exit(1);
	}
	reading(tab,aloc);
	close(aloc.fd);
}
