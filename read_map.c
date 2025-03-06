/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:26:14 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/01 16:13:39 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int	get_height(t_fdf *tab)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(tab->av[1], O_RDONLY);
	if(fd == -1)
		exit(0);
	line = get_next_line(fd);
	height = 0;
	while(line)
	{
		height++;
		free(line);
		line = get_next_line(fd);

	}
	close (fd);
	return height;
}
int get_width(t_fdf *tab)
{
	int fd;
	char *line;
	char **arr;
	int width;
	fd = open(tab->av[1], O_RDONLY);
	if(fd == -1)
		exit(0);
	line = get_next_line(fd);
	if(!line)
	{
		close(fd);
		return (-1);
	}
	arr = ft_split(line,' ');
	if(!arr)
	{
		free(line);
		close(fd);
		return -1;
	}
	width = 0;
	while (arr[width])
	{
		width++;
	}
	free(line);
	ft_free(arr);
	close(fd);
	return width;
}

int **allocation_for_map(t_fdf *tab)
{
	int **result;
	int index;
	tab->height = get_height(tab);
	tab->width = get_width(tab);
	result = malloc(sizeof(int *) * tab->height);
	if(!result)
	{
		free(result);
		exit(0);
	}
	index = 0;
	while (index < tab-> height)
	{
		result[index] = malloc(sizeof(int) * tab->width);
		if(!result[index])
		{
			int j = 0;
			while(j < index)
			{
				free(result[j]);
				j++;
			}
			free(result);
			exit(-1);
		}
		index++;
	}
	return result;
}
void read_file(t_fdf *tab)
{
	char	*str;
	char	**s_str;
	int		fd;
	int		index1;
	int		index2;

	tab->map = allocation_for_map(tab);
	tab->height = get_height(tab);
	tab->width = get_width(tab);
	fd = open(tab->av[1],O_RDONLY);
	if (fd == -1)
		exit(0);
	str = get_next_line(fd);
	index1 = 0;

	while (str)
	{
		s_str = ft_split(str,' ');
		index2  = 0;
		while (index2 < tab->width)
		{

			tab->map[index1][index2] = ft_atoi(s_str[index2]);
			index2++;
		}
		free(str);
		ft_free(s_str);
		str = get_next_line(fd);
		index1++;
	}
	close(fd);
}
