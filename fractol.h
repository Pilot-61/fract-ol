/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/04 21:22:53 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define CELESTIAL_BLUE 0x4997D0
# define KEY_ESC 53
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define DARK_BROWN   0x421E0F
# define DARK_BLUE    0x09012F
# define BLUE         0x00076E
# define LIGHT_BLUE   0x0C2C8A
# define SKY_BLUE     0x1852B1
# define LIGHT_CYAN   0x86B5E5
# define LIGHT_YELLOW 0xF8C95F
# define ORANGE       0xFFAA00
# define BROWN        0x995700
# define PALE_CYAN    0x8CCEEA

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
	int		color;
}			t_fractol;

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_cordinate
{
	int	x;
	int	y;
}			t_cordinate;

void		init_mlx(t_fractol *fractol);
void		draw_fractol(t_fractol *fractol);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void		error(char *str);
int			key_press(int keycode, t_fractol *fractol);
int			mouse_press(int keycode, int x, int y, t_fractol *fractol);
double		mes_atof(char *c);
void		color_infinity(t_fractol *fractol, int i);
#endif