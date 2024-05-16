/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:14 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/16 01:13:49 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mes_parse(int ac, char **av, t_fractol *fractol)
{
	fractol->name = av[1];
	if (ac == 2 || ac == 4)
	{
		if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		{
			if (ac != 2)
				error("invalid number of arguments ./fractol mnadelbrot\n");
			fractol->fractol = 1;
			fractol->x = 0.0;
			fractol->y = 0.0;
		}
		else if (ft_strncmp(fractol->name, "julia", 5) == 0)
		{
			if (ac != 4)
				error("invalid number of arguments ./fractol julia cx cy\n");
			fractol->fractol = 2;
			fractol->x = mes_atof(av[2]);
			fractol->y = mes_atof(av[3]);
		}
	}
	else
		error("invalid fractol name\n");
}

int close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx.mlx, fractol->mlx.img);
	mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win);
	exit(0);
	return 0;
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	mes_parse(ac, av, &fractol);
	init_mlx(&fractol);
	draw_fractol(&fractol);
	mlx_put_image_to_window(fractol.mlx.mlx, fractol.mlx.win,
		fractol.mlx.img, 0, 0);
	mlx_key_hook(fractol.mlx.win, key_press, &fractol);
	mlx_mouse_hook(fractol.mlx.win, mouse_press, &fractol);
	mlx_hook(fractol.mlx.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx.mlx);
	return (0);
}
