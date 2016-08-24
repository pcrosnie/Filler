/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 11:42:44 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/24 16:46:48 by pcrosnie         ###   ########.fr       */
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

int		ft_check_my_quart(t_data *ptr, t_pos *e)
{
	if (e->my_posXmax <= ptr->map_width / 2 && e->my_posYmax <= ptr->map_height / 2)
		return (1);
	if (e->my_posXmax >= ptr->map_width / 2 && e->my_posXmin >= ptr->map_width / 2)
	{
		if (e->my_posYmax <= ptr->map_height / 2)
			return (2);
		if (e->my_posYmin >= ptr->map_height / 2)
			return (4);
	}
	if (e->my_posXmax <= ptr->map_width / 2 && e->my_posYmin >= ptr->map_height / 2)
		return (3);
	return (0);
}

int		ft_check_adv_quart(t_data *ptr, t_pos *e)
{
	if (e->adv_posXmax <= ptr->map_width / 2 && e->adv_posYmax <= ptr->map_height / 2)
		return (1);
	if (e->adv_posXmax >= ptr->map_width / 2 && e->adv_posXmin >= ptr->map_width / 2)
	{
		if (e->adv_posYmax <= ptr->map_height / 2)
			return (2);
		if (e->adv_posYmin >= ptr->map_height / 2)
			return (4);
	}
	if (e->adv_posXmax <= ptr->map_width / 2 && e->adv_posYmin >= ptr->map_height / 2)
		return (3);
	return (0);
}

void	ft_check_for_strat(t_data *ptr, t_pos *e)
{
	ptr->my_quart = ft_check_my_quart(ptr, e);
	ptr->adv_quart = ft_check_adv_quart(ptr, e);
	ptr->strat = 1;
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
	if (ptr->my_quart == 0)
		ft_check_for_strat(ptr, e);
	if (ptr->strat == 1)
		ft_reach_center(ptr);
/*	if (ptr->strat == 2)
		ft_block(ptr, e);
	if (ptr->strat == 3)
		ft_fill_adv(ptr, e);
	if (ptr->strat == 4)
		ft_fill_mine(ptr, e);*/
}
