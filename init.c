/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:46:12 by mes-salh          #+#    #+#             */
/*   Updated: 2024/06/15 02:05:47 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

static void	data_init(t_fractol *fractol)
{
	fractol->max_iter = 200;
	fractol->escape_value = 4.0;
	fractol->zoom = 1.1;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx.mlx = mlx_init();
	if (!fractol->mlx.mlx)
		error("Error: mlx_init() failed\n");
	fractol->mlx.win = mlx_new_window(fractol->mlx.mlx,
			WIDTH, HEIGHT, fractol->name);
	if (!fractol->mlx.win)
		error("Error: mlx_new_window() failed\n");
	fractol->mlx.img = mlx_new_image(fractol->mlx.mlx, WIDTH, HEIGHT);
	if (!fractol->mlx.img)
	{
		mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win);
		error("Error: mlx_new_image() failed\n");
	}
	fractol->mlx.addr = mlx_get_data_addr(fractol->mlx.img, &fractol->mlx.bpp,
			&fractol->mlx.line_len, &fractol->mlx.endian);
	data_init(fractol);
}
