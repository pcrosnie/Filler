/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_suit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:29:06 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/25 13:54:51 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_dist_center(int x1, int y1, int x2, int y2)
{
	int dist;

	dist = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	(dist < 0) ? dist *= -1 : 0;
	return (dist);
}

int		ft_check_for_center(t_data *ptr)
{
	if (ptr->map[ptr->map_height / 2][ptr->map_width / 2] != '.')
		return (1);
	else
		return (0);
}

void	ft_reach_center(t_data *ptr)
{
	int i;
	int dist;
	int	record_dist;
	int record;

	i = 0;
	record = 0;
	record_dist = ft_dist_center(ptr->map_height / 2, ptr->map_width / 2, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
	while (i < ptr->nb_sol)
	{
//		ft_output(ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
		dist = ft_dist_center(ptr->map_height / 2, ptr->map_width / 2, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
		if (dist < record_dist)
		{
			record = i;
			record_dist = dist;
		}
		i++;
	}
	if (ft_check_for_center(ptr) == 1)
		ptr->strat++;
	ft_output(ptr->possible_positions[0][record] - 1, ptr->possible_positions[1][record]);
}

int		ft_check_if_advance(t_data *ptr, t_pos *e)
{
	if ((ptr->adv_quart == 1 || ptr->adv_quart == 2) && e->adv_posYmax > ptr->map_height / 2)
		return (e->adv_posYmax);
	if ((ptr->adv_quart == 3 || ptr->adv_quart == 4) && e->adv_posYmin < ptr->map_height / 2)
		return (e->adv_posYmin);
	if (ptr->my_quart == 1 || ptr->my_quart == 2)
		return (e->my_posYmax);
	if (ptr->my_quart == 3 || ptr->my_quart == 4)
		return (e->my_posYmin);
	return (0);
}
/*
int		ft_check_defense(t_data *ptr, t_pos *e)
{
	if ((ptr->adv_quart == 1 || ptr->adv_quart == 2) && e->adv_posYmax > ptr->map_height / 2)
		return (e->adv_posYmax);
	if ((ptr->adv_quart == 3 || ptr->adv_quart == 4) && e->adv_posYmin < ptr->map_height / 2)
		return (e->adv_posYmin);
	if (ptr->my_quart == 1 || ptr->my_quart == 2)
		return (e->my_posYmax);
	if (ptr->my_quart == 3 || ptr->my_quart == 4)
		return (e->my_posYmin);
	return (0);
}*/

int		ft_check_in_line(t_data *ptr)
{
	if (ptr->my_quart == 1 || ptr->my_quart == 3)
		return (ptr->map_width);
	return (0);
}

void	ft_set_line(t_data *ptr, int targetY, int record)
{
	int targetX;
	int record_dist;
	int dist;
	int i;

	i = 0;
	targetX = ft_check_in_line(ptr);
	record_dist = ft_dist_center(targetY, targetY, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
	while (i < ptr->nb_sol)
	{
		dist = ft_dist_center(targetY, targetY, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
		if (dist < record_dist)
		{
			record = i;
			record_dist = dist;
		}
		i++;
	}
	ft_output(ptr->possible_positions[0][record] - 1, ptr->possible_positions[1][record]);	
}

void	ft_block(t_data *ptr, t_pos *e)
{
	int line;

	if (ptr->map[ptr->map_height / 2][ptr->map_width / 2] == ptr->c)
		ptr->center = 1;
	else
		ptr->center = 2;
	line = ft_check_if_advance(ptr, e);
	ft_set_line(ptr, line, 0);
}



