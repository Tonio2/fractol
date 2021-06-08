/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:42:59 by alabalet          #+#    #+#             */
/*   Updated: 2021/06/08 16:33:55 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_color(int R, int G, int B)
{
	return (R * 256 * 256 + G * 256 + B);
}

void	ft_init(t_data *v)
{
	v->dim_x = 1920;
	v->dim_y = 1080;
	v->color = ft_color(255, 0, 0);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->dim_y, v->dim_x, "Fractol");
	v->img.img = mlx_new_image(v->mlx, v->dim_y, v->dim_x);
	v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bpp,
			&v->img.line_len, &v->img.endian);
}

int	ft_update(t_data *v)
{
	int		px_x;
	int		px_y;
	int		R;
	int		G;
	int		B;

	R = 0;
	B = 100;
	R = 200;
	v->color = ft_color(R, 0, 0);
	px_y = -1;
	while (++px_y < v->dim_y)
	{
		px_x = -1;
		while (++px_x < v->dim_x)
		{
			R = ((R + 4) * 3) % 255;
			G = ((G + 7) * 36) % 255;
			B = ((B + 45) * 84) % 255;
			v->color = ft_color(R, G, B);
			my_mlx_pixel_put(&v->img, px_x, px_y, v->color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	v;

	ft_init(&v);
	mlx_loop_hook(v.mlx, ft_update, &v);
	mlx_loop(v.mlx);
	return (0);
}
