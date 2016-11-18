/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:49:52 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/18 13:20:17 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		has_vertical(t_data *ptr)
{
	int i;

	i = 1;
	while (i < ptr->nb_sol)
	{
		if (ptr->possible_positions[1][0] == ptr->possible_positions[1][i])
			return (0);
		i++;
	}
	return (1);
}

int		build_wall(t_data *ptr)
{
	int i;

	i = 0;
	while (i < ptr->nb_sol)
	{
		if (/*ptr->set_vert == 0 && */has_vertical(ptr) == 1)
		{
			ptr->set_vert = 1;
			return (ptr->nb_sol / 2);
		}
		if (ptr->possible_positions[1][i] - ptr->first_posy == ptr->ref_line || ptr->possible_positions[1][i] - ptr->first_posy == ptr->ref_line + 1 || ptr->possible_positions[1][i] - ptr->first_posy == ptr->ref_line - 1)
		{
			if (i > 1)
				return (i - 1);
			return (i);
		}
		i++;
	}
	return (ptr->nb_sol / 2);
}

void	ft_algo(t_data *ptr)
{
//	if (ptr->strat == 0)
		ptr->sol_index = build_wall(ptr);
//	if (ptr->strat == 1)
//		fill_adv_part();
}
