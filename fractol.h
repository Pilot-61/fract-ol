/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/03/27 07:38:19 by mes-salh         ###   ########.fr       */
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
# define MAX_ITER 42
# define ZOOM 1.1
# define MOVE 0.1
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define CYAN 0x00FFFF
# define LAVA_RED 0xFF3300
# define LAVA_ORANGE 0xFF6600
# define LAVA_YELLOW 0xFF9900
# define LAVA_GREEN 0xCCFF00
# define LAVA_BLUE 0x66FF00
# define LAVA_PURPLE 0x33FF00
# define LAVA_CYAN 0x00FF33
# define LAVA_WHITE 0x00FF66
# define LAVA_BLACK 0x00FF99
# define LAVA_GRAY 0x00FFCC

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
	double	escape_value; //escape value
}			t_fractol; //struct for fractol

typedef struct s_complex
{
	double	r; //real part
	double	i; //imaginary part
}			t_complex; //struct for complex number

void		init_mlx(t_fractol *fractol);
void		draw_fractol(t_fractol *fractol);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
double		scale(double value, double in_min, double in_max, double out_min, double out_max);
double		map(int value, int in_min, int in_max, int out_min, int out_max);
t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void		error(char *str);


#endif