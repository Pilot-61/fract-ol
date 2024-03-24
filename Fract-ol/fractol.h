/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/03/24 03:11:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ZOOM 1.1
# define MOVE 0.1

typedef struct s_mlx
{
	void	*mlx; //mlx_init()
	void	*win; //mlx_new_window()
	void	*img; //mlx_new_image()
	char	*addr; //mlx_get_data_addr()
	int		bpp; //bits per pixel
	int		line_len; //line length
	int		endian; //endian
}			t_mlx; //struct for mlx

typedef struct s_fractol
{
	t_mlx	mlx; //struct for mlx
	char	*name; //fractol name
	int		fractol; //fractol type
	double	x; //x coordinate
	double	y; //y coordinate
	double	zoom; //zoom
	int		max_iter; //max iteration
}			t_fractol; //struct for fractol

void		init_mlx(t_fractol *fractol);
void		draw_fractol(t_fractol *fractol);
int			mandelbrot(t_fractol *fractol, double x, double y);
int			julia(t_fractol *fractol, double x, double y);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

#endif