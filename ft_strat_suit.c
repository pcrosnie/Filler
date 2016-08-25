/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_suit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:29:06 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/25 10:47:26 by pcrosnie         ###   ########.fr       */
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

void	ft_reach_center(t_data *ptr)
{
	int i;
	int dist;
	int	record_dist;
	int record;

	i = 0;
	record = 0;
	record_dist = ft_dist_center(ptr->map_width / 2, ptr->map_height / 2, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
	while (i < ptr->nb_sol)
	{
	//	ft_output(ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
		dist = ft_dist_center(ptr->map_width / 2, ptr->map_height / 2, ptr->possible_positions[0][i] - 1, ptr->possible_positions[1][i]);
		if (dist < record_dist)
		{
			record = i;
			record_dist = dist;
		}
		i++;
	}
	ft_output(ptr->possible_positions[0][record] - 1, ptr->possible_positions[1][record]);
}



