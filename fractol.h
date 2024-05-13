/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 00:18:15 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 100
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define CELESTIAL_BLUE 0x4997D0
# define KEY_ESC 53
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_mlx;

typedef struct s_fractol
{
	t_mlx	mlx;
	char	*name;
	int		fractol;
	double	x;
	double	y;
	double	zoom;
	int		max_iter;
	double	escape_value;

}			t_fractol;

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

void		init_mlx(t_fractol *fractol);
void		draw_fractol(t_fractol *fractol);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void		error(char *str);
int			key_press(int keycode, t_fractol *fractol);
int			mouse_press(int keycode, int x, int y, t_fractol *fractol);
double		ft_atof(char *str);

#endif