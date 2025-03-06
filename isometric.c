/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:29:37 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/06 00:22:17 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


void isometric(int *x , int *y , int z)
{
	if(!x || !y)
	{
		return;
	}
	float previos_x;
	float previos_y;
	previos_x = *x;
	previos_y = *y;
 	*x = (previos_x - previos_y) * cos(0.53469);
	*y = (previos_x + previos_y) * sin(0.53469) - z;
}

