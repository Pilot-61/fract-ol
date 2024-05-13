/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:14 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 00:23:20 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.name = av[1];
	if (ft_strncmp(fractol.name, "mandelbrot", 10) == 0)
	{
		if (ac != 2)
			error("Error: invalid number of arguments ./fractol mnadelbrot\n");
		fractol.fractol = 1;
		fractol.x = 0.0;
		fractol.y = 0.0;
	}
	else if (ft_strncmp(fractol.name, "julia", 5) == 0)
	{
		if (ac != 4)
			error("Error: invalid number of arguments ./fractol julia cx cy\n");
		fractol.fractol = 2;
		fractol.x = ft_atof(av[2]);
		fractol.y = ft_atof(av[3]);
	}
	else
		error("Error: invalid fractol name\n");
	init_mlx(&fractol);
	draw_fractol(&fractol);
	mlx_put_image_to_window(fractol.mlx.mlx, fractol.mlx.win,
		fractol.mlx.img, 0, 0);
	mlx_key_hook(fractol.mlx.win, key_press, &fractol);
	mlx_mouse_hook(fractol.mlx.win, mouse_press, &fractol);
	mlx_loop(fractol.mlx.mlx);
	return (0);
}
