/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ram.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:30:35 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 18:06:59 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_check_file(char *valid, char **av)
{
	valid = ft_strchr(av[1], '.');
	if (!valid || ft_strcmp(valid, ".fdf"))
	{
		ft_putstr_fd("error : nari kabatiha khaso ykon .fdf ", 2);
		exit (0);
	}
}
