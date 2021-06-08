/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:42:59 by alabalet          #+#    #+#             */
/*   Updated: 2021/06/08 18:11:15 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_color(t_cplx c)
{
	if (c.mod > 1)
		return (0);
	else
		return (0x00FFFFFF);
}

void	ft_init(t_data *v)
{
	v->dim_x = 1920;
	v->dim_y = 1080;
	v->height = 9;
	v->width = 16;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->dim_x, v->dim_y, "Fractol");
	v->img.img = mlx_new_image(v->mlx, v->dim_x, v->dim_y);
	v->img.addr = mlx_get_data_addr(v->img.img, &v->img.bpp,
			&v->img.line_len, &v->img.endian);
}

t_cplx	ft_compute_coor(t_data *v, int px_x, int px_y)
{
	t_cplx	ret;

	ret.x = -v->width / 2 + px_x * v->width / v->dim_x;
	ret.y = v->height / 2 - px_y * v->height / v->dim_y;
	return (ret);
}

int	ft_update(t_data *v)
{
	int		px_x;
	int		px_y;
	t_cplx	c;
	int		color;

	px_y = -1;
	while (++px_y < v->dim_y)
	{
		px_x = -1;
		while (++px_x < v->dim_x)
		{
			c = ft_compute_coor(v, px_x, px_y);
			ft_pol(&c);
			color = ft_color(c);
			my_mlx_pixel_put(&v->img, px_x, px_y, color);
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	return (0);
}

int	ft_exit(int keycode, t_data *v)
{
	keycode++;
	v++;
	exit(0);
	return (0);
}

int	press_hook(int keycode, t_data *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data	v;

	ft_init(&v);
	mlx_loop_hook(v.mlx, ft_update, &v);
	mlx_hook(v.win, 2, 0L, press_hook, &v);
	mlx_hook(v.win, 17, 0L, ft_exit, &v);
	mlx_loop(v.mlx);
	return (0);
}
