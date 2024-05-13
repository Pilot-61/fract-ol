/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:14 by mes-salh          #+#    #+#             */
/*   Updated: 2024/03/24 03:03:49 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0
			|| ft_strncmp(av[1], "julia", 5) == 0
			|| ft_strncmp(av[1], "burningship", 11) == 0))
	{
		fractol.name = av[1];
		init_mlx(&fractol);
		// fractol_render(&fractol);
		mlx_loop(fractol.mlx.mlx);
	}
	return (0);
}
