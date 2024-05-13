/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:14 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/12 18:16:58 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		if (ac != 2)
			error("Error: invalid number of arguments : ./fractol mnadelbrot\n");
		fractol.fractol = 1;
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		if (ac != 4)
			error("Error: invalid number of arguments ./fractol julia cx cy\n");
		fractol.fractol = 2;
	}
	else
		error("Error: invalid fractol name\n");
	fractol.name = av[1];                                      
	init_mlx(&fractol);
	draw_fractol(&fractol);
	mlx_put_image_to_window(fractol.mlx.mlx, fractol.mlx.win, fractol.mlx.img, 0, 0);
	mlx_loop(fractol.mlx.mlx);
	return (0);
}
