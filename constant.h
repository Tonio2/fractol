/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:22 by alabalet          #+#    #+#             */
/*   Updated: 2021/06/08 17:42:17 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_cplx
{
	long double	x;
	long double	y;
	long double	mod;
	long double	arg;
}				t_cplx;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			dim_y;
	int			dim_x;
	long double	height;
	long double	width;
}				t_data;

void	ft_pol(t_cplx *c);
void	ft_alg(t_cplx *c);
void	ft_print_cplx(t_cplx c);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_color(t_cplx c);
void	ft_init(t_data *v);
int		ft_exit(int keycode, t_data *v);
int		ft_update(t_data *v);

#endif