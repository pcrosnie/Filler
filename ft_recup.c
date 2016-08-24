/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:00:27 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/24 12:30:38 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_recup_my_x(t_data *ptr, t_pos *e)
{
	int i;
	int j;

	i = 0;
	e->my_posXmin = ptr->map_width;
	e->my_posXmax = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == ptr->c)
			{
				if (j < e->my_posXmin)
					e->my_posXmin = j;
				if (j > e->my_posXmax)
					e->my_posXmax = j;
			}
			j++;
		}
		i++;
	}
}

void    ft_recup_my_y(t_data *ptr, t_pos *e)
{
	int i;
	int j;

	i = 0;
	e->my_posYmin = ptr->map_height;
	e->my_posYmax = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == ptr->c)
			{
				if (i < e->my_posYmin)
					e->my_posYmin = i - 1;
				if (i > e->my_posYmax)
					e->my_posYmax = i - 1;
			}
			j++;
		}
		i++;
	}
}

void    ft_recup_adv_x(t_data *ptr, t_pos *e)
{
	int i;
	int j;
	char c;

	c = 'X';
	(ptr->c == 'X') ? c = 'O' : 0;
	i = 0;
	e->adv_posXmin = ptr->map_width;
	e->adv_posXmax = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == c || ptr->map[i][j] == c + 32)
			{
				if (j < e->adv_posXmin)
					e->adv_posXmin = j;
				if (j > e->adv_posXmax)
					e->adv_posXmax = j;
			}
			j++;
		}
		i++;
	}
}

void    ft_recup_adv_y(t_data *ptr, t_pos *e)
{
	int i;
	int j;
	char c;

	c = 'X';
	(ptr->c == 'X') ? c = 'O' : 0;
	i = 0;
	e->adv_posYmin = ptr->map_width;
	e->adv_posYmax = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == c || ptr->map[i][j] == c + 32)
			{
				if (i < e->adv_posYmin)
					e->adv_posYmin = i - 1;
				if (i > e->adv_posYmax)
					e->adv_posYmax = i - 1;
			}
			j++;
		}
		i++;
	}
}
