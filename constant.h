/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:22 by alabalet          #+#    #+#             */
/*   Updated: 2021/06/08 16:20:48 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# include <mlx.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		dim_y;
	int		dim_x;
	int		color;
}			t_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_color(int R, int G, int B);
void	ft_init(t_data *v);
int		ft_update(t_data *v);

#endif