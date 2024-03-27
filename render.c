/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:15:30 by mes-salh          #+#    #+#             */
/*   Updated: 2024/03/27 08:17:27 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    int    offset;
    
    offset = (y * mlx->line_len + x * (mlx->bpp / 8));
    *(unsigned int *)(mlx->addr + offset) = color;
}

void    handle_pixel(t_fractol *fractol, int x, int y)
{
    t_complex    c;
    t_complex    z;
    int         i;
    int         color;
    
    z.r = 0.0;
    z.i = 0.0;
    i = 0;
    
    c.r = map(x, 0, WIDTH, -2.0, 2.0);
    c.i = map(y, 0, HEIGHT, -2.0, 2.0);
    
    while (i < fractol->max_iter)
    {
        z = complex_sum(complex_square(z), c);
        if ((z.r * z.r )+ (z.i * z.i) > fractol->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractol->max_iter);
            my_mlx_pixel_put(&fractol->mlx, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractol->mlx, x, y, LAVA_GRAY);
    
}

void	draw_fractol(t_fractol *fractol)
{
    int x;
    int y;
    
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_pixel(fractol, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
}