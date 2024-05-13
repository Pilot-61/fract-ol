/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 22:48:28 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 00:18:32 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP)
		fractol->zoom *= 1.1;
	else if (keycode == MOUSE_SCROLL_DOWN)
		fractol->zoom *= 0.9;
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->mlx.img, 0, 0);
	return (0);
}

int	key_press(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win);
		exit(0);
	}
	return (0);
}
