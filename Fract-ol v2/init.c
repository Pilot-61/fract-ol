/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:46:12 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/13 02:42:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
 void    error(char *str)
{
    ft_putstr_fd(str, 2); //print error message
    exit(1); //exit the program
}

static void    data_init(t_fractol *fractol)
{
    fractol->max_iter = 100; //set max_iter to MAX_ITER
    fractol->escape_value = 4.0; //set escape_value to 4.0
}

void    init_mlx(t_fractol *fractol)
{
    fractol->mlx.mlx = mlx_init(); //initialize mlx
    if (!fractol->mlx.mlx) //if mlx is not initialized
        error("Error: mlx_init() failed\n"); //print error message
    fractol->mlx.win = mlx_new_window(fractol->mlx.mlx, WIDTH, HEIGHT, fractol->name); //create a new window
    if (!fractol->mlx.win) //if window is not created
    {
        error("Error: mlx_new_window() failed\n"); //print error message
    }
    fractol->mlx.img = mlx_new_image(fractol->mlx.mlx, WIDTH, HEIGHT); //create a new image
    if (!fractol->mlx.img) //if image is not created
    {
        mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win); //destroy window
        error("Error: mlx_new_image() failed\n"); //print error message
    }
    fractol->mlx.addr = mlx_get_data_addr(fractol->mlx.img, &fractol->mlx.bpp, &fractol->mlx.line_len, &fractol->mlx.endian); //get the address of the image
    data_init(fractol); //initialize data
mlx_key_hook(fractol->mlx.win, key_press, fractol);


}
