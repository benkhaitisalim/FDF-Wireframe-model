/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:26:14 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/12 02:56:47 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
int	get_height(t_fdf *tab)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(tab->av[1], O_RDONLY);
	if(fd == -1)
		exit(0);
	height = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close (fd);
	free(line);
	return height;
}
int get_width(t_fdf *tab)
{
	int fd;
	char *line;
	char **arr;
	int width;
	fd = open(tab->av[1], O_RDONLY);
	line = get_next_line(fd);
	arr = ft_split(line,' ');
	if(!line || !arr)
	{
		ft_free(arr);
		exit(-1);
	}
	width = 0;
	while (arr[width])
	{
		width++;
	}
	close(fd);
	free(line);
	ft_free(arr);
	return width;
}

int **allocation_for_map(t_fdf *tab)
{
	int **result;
	int index;
	tab->height = get_height(tab);
	tab->width = get_width(tab);
	result = ft_calloc((sizeof(int  *)) * (tab->height), sizeof(int * ));
	if(!result)
	{
		free(result);
		exit(0);

	}
	index = 0;
	while (index < tab->height)
	{
		result[index] = ft_calloc(sizeof(int ) * (tab->width),sizeof(int));
		index++;
	}
	return result;
}
void read_file(t_fdf *tab)
{ 
	char	*str;
	char	**s_str = NULL;
	int		fd;
	int		index1;
	int		index2;
	fd = open(tab->av[1],O_RDONLY);
	str = get_next_line(fd);
	tab->map = allocation_for_map(tab);
	if (fd == -1 || !str)
	{
		close(fd);
		free(str);
		exit(0);
	}   
	index1 = 0;
	while (str && index1 < tab->height)
	{ 
		index2  = 0;
		s_str = ft_split(str,' ');
		while (s_str[index2]&& index2 < tab->width)
		{
			tab->map[index1][index2] = ft_atoi(s_str[index2]);
			index2++;
		}
		ft_free(s_str);
		free(str);
		str = get_next_line(fd);
		index1++;
	}
	close(fd);
}
