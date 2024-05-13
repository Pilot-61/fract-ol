/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/13 02:42:45 by mes-salh         ###   ########.fr       */
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
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define CELESTIAL_BLUE 0x4997D0
# define SUNSET_ORANGE 0xFF7F50
# define AMETHYST_PURPLE 0x9966CC
# define EMERALD_GREEN 0x50C878
# define CORAL_PINK 0xFF6F61
# define GOLDENROD_YELLOW 0xDAA520
# define LAVENDER_PURPLE 0xE6E6FA
# define TURQUOISE_BLUE 0x40E0D0
# define RUBY_RED 0xE0115F
# define SAPPHIRE_BLUE 0x0F52BA
#define KEY_ESC 53 // Example: ASCII value for ESC key
#define KEY_DOWN_ARROW 125 // Example: ASCII value for down arrow key
#define KEY_UP_ARROW 126 // Example: ASCII value for up arrow key
#define KEY_LEFT_ARROW 123 // Example: ASCII value for left arrow key
#define KEY_RIGHT_ARROW 124 // Example: ASCII value for right arrow key
#define KEY_PLUS 69 // Example: ASCII value for + key
#define KEY_MINUS 78 // Example: ASCII value for - key




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
t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void		error(char *str);
int key_press(int keycode, t_fractol *fractol);

#endif