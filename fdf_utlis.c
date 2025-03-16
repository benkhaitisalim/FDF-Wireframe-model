/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:59:59 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/16 05:35:26 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else  
        return (b);
}

int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    else  
        return (b);
}

int ft_strcmp(char *str, char *str2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i] == str2[j] && str[i] && str[j])
    {
        i++;
        j++;
    }
    return(str[i] - str2[j]);
}

int ft_error(t_data *data)
{
	if (!data->img) 
	{
		mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
		exit(0);
	}
	return 0;
}

int ft_abs(int num)
{
    if(num < 0)
    {
        num = -num;
    }
    return num;
}

