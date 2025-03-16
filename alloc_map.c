/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:51:27 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 05:55:53 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(t_fdf *tab)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(tab->av[1], O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	if (!line || fd == -1)
	{
		ft_putstr_fd("error ", 2);
		close (fd);
		exit (1);
	}
	while (line != NULL)
	{
		height++;
		line = get_next_line(fd);
		free(line);
	}
	close (fd);
	free(line);
	return (height);
}

int	get_width(t_fdf *tab)
{
	int		fd;
	char	*line;
	char	**arr;
	int		width;

	fd = open(tab->av[1], O_RDONLY);
	line = get_next_line(fd);
	arr = ft_split(line, ' ');
	if (!line || !arr || fd == -1)
	{
		ft_putstr_fd("error ", 2);
		close (fd);
		ft_free(arr);
		free(line);
		exit(-1);
	}
	width = 0;
	while (arr[width])
		width++;
	close(fd);
	free(line);
	ft_free(arr);
	return (width);
}

int	**allocation_for_map(t_fdf *tab)
{
	int	**result;
	int	index;

	tab->height = get_height(tab);
	tab->width = get_width(tab);
	result = ft_calloc((sizeof(int *)) * (tab->height), sizeof(int *));
	if (!result)
	{
		free(result);
		exit(0);
	}
	index = 0;
	while (index < tab->height)
	{
		result[index] = ft_calloc(sizeof(int ) * (tab->width), sizeof(int));
		index++;
	}
	return (result);
}
