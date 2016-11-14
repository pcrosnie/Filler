/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:49:52 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/14 12:14:21 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		build_wall(t_data *ptr)
{
	int i;

	i = 0;
	while (i < ptr->nb_sol)
	{
		if (ptr->possible_positions[1][i] == ptr->ref_line)
			return (i);
		i++;
	}
	return (ptr->nb_sol / 2);	
}

void	ft_algo(t_data *ptr)
{
	if (ptr->strat == 0)
		ptr->sol_index = build_wall(ptr);
//	if (ptr->strat == 1)
//		fill_adv_part();
}
