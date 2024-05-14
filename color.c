/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 05:55:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 06:02:43 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_color_index(int i)
{
	return (i % 10);
}

int	determine_color(int color_index)
{
	int	color;

	color = BLACK;
	if (color_index == 0)
		color = DARK_BLUE;
	else if (color_index == 1)
		color = BLUE;
	else if (color_index == 2)
		color = LIGHT_BLUE;
	else if (color_index == 3)
		color = SKY_BLUE;
	else if (color_index == 4)
		color = LIGHT_CYAN;
	else if (color_index == 5)
		color = PALE_CYAN;
	else if (color_index == 6)
		color = LIGHT_YELLOW;
	else if (color_index == 7)
		color = ORANGE;
	else if (color_index == 8)
		color = BROWN;
	else if (color_index == 9)
		color = DARK_BROWN;
	return (color);
}

void	color_divergence(t_fractol *fractol, int i)
{
	int	color_index;
	int	color;

	if (i == fractol->max_iter)
	{
		fractol->color = BLACK;
	}
	else
	{
		color_index = calculate_color_index(i);
		color = determine_color(color_index);
		fractol->color = color;
	}
}
