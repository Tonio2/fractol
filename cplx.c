/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:03:45 by alabalet          #+#    #+#             */
/*   Updated: 2021/06/08 18:10:31 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	ft_pol(t_cplx *c)
{
	c->mod = sqrtl(c->x * c->x + c->y * c->y);
	if (c->mod == 0)
		c->arg = 0;
	else
	{
		if (c->y >= 0)
			c->arg = acosl(c->x / c->mod);
		else
			c->arg = -acosl(c->x / c->mod);
	}
}

void	ft_alg(t_cplx *c)
{
	c->x = c->mod * cosl(c->arg);
	c->y = c->mod * sinl(c->arg);
}

void	ft_print_cplx(t_cplx c)
{
	printf("c = %Lf + i . %Lf\n", c.x, c.y);
	printf("c = %Lfei(%Lf)\n", c.mod, c.arg);
}
