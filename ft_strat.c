/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 11:42:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/24 12:32:05 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put(t_pos *e)
{
	ft_putnbr(e->my_posXmin);
	ft_putchar('\n');
	ft_putnbr(e->my_posYmin);
	ft_putchar('\n');
	ft_putnbr(e->my_posXmax);
	ft_putchar('\n');
	ft_putnbr(e->my_posYmax);
	ft_putchar('\n');
	ft_putnbr(e->adv_posXmin);
	ft_putchar('\n');
	ft_putnbr(e->adv_posYmin);
	ft_putchar('\n');
	ft_putnbr(e->adv_posXmax);
	ft_putchar('\n');
	ft_putnbr(e->adv_posYmax);
	ft_putchar('\n');
}

void	ft_strat(t_data *ptr)
{
	t_pos *e;

	e = (t_pos *)malloc(sizeof(t_pos));
	ft_recup_my_x(ptr, e);
	ft_recup_my_y(ptr, e);
	ft_recup_adv_x(ptr, e);
	ft_recup_adv_y(ptr, e);
//	ft_put(e);
	
}
