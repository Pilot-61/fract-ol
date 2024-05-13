/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 22:48:28 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/13 00:20:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ZOOM_FACTOR 1.1 // Zoom factor


int key_press(int keycode, t_fractol *fractol)
{
    if (keycode == KEY_ESC) // If ESC key is pressed
    {
        mlx_destroy_window(fractol->mlx.mlx, fractol->mlx.win); // Destroy window
        exit(0); // Exit the program
    }
    else if (keycode == KEY_DOWN_ARROW) // If down arrow key is pressed
    {
        fractol->y += MOVE; // Move down
        draw_fractol(fractol); // Draw fractol
    }
    else if (keycode == KEY_UP_ARROW) // If up arrow key is pressed
    {
        fractol->y -= MOVE; // Move up
        draw_fractol(fractol); // Draw fractol
    }
    else if (keycode == KEY_LEFT_ARROW) // If left arrow key is pressed
    {
        fractol->x -= MOVE; // Move left
        draw_fractol(fractol); // Draw fractol
    }
    else if (keycode == KEY_RIGHT_ARROW) // If right arrow key is pressed
    {
        fractol->x += MOVE; // Move right
        draw_fractol(fractol); // Draw fractol
    }
    else if (keycode == KEY_PLUS) // If + key is pressed
    {
        fractol->zoom *= ZOOM_FACTOR; // Zoom in
        draw_fractol(fractol); // Draw fractol
    }
    else if (keycode == KEY_MINUS) // If - key is pressed
    {
        fractol->zoom /= ZOOM_FACTOR; // Zoom out
        draw_fractol(fractol); // Draw fractol
    }
    return (0);
}