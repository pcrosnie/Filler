/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:53:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/15 15:11:11 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_possible_sol(t_data *ptr, int i, int j)
{
	int index;
	int	touch_nb;
	char err;

	err = (ptr->c == 'X') ? 'O' : 'X';
	index = 0;
	touch_nb = 0;
	while (index < ptr->res_index)
	{
		if (i + (int)ptr->piece[1][index] < 0 || i + (int)ptr->piece[1][index] >= ptr->map_height)
			return (0);
		if (j + (int)ptr->piece[0][index] < 0 || j + (int)ptr->piece[0][index] >= ptr->map_width)
			return (0);
		if (ptr->map[i + (int)ptr->piece[1][index]][j + (int)ptr->piece[0][index]] == err || ptr->map[i + (int)ptr->piece[1][index]][j + (int)ptr->piece[0][index]] == err + 32)
			return (0);
		if (ptr->map[i + (int)ptr->piece[1][index]][j + (int)ptr->piece[0][index]] == ptr->c || ptr->map[i + (int)ptr->piece[1][index]][j + (int)ptr->piece[0][index]] == ptr->c + 32)
			touch_nb++;
		index++;
	}
	if (touch_nb == 1)
		return (1);
	return (0);
}

void	get_ref_line(t_data *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == ptr->c)
			{
				ptr->ref_line = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_possible_positions(t_data *ptr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ptr->nb_sol = 0;
	if (ptr->ref_line == 0)
		get_ref_line(ptr);
	if (!ptr->possible_positions)
	{
		ptr->possible_positions = (char **)ft_memalloc(sizeof(char *) * 2);
		ptr->possible_positions[0] = (char *)ft_memalloc(sizeof(char) * (ptr->map_height * ptr->map_width));
		ptr->possible_positions[1] = (char *)ft_memalloc(sizeof(char) * (ptr->map_height * ptr->map_width));
	}
//	ptr->possible_positions[0] = ft_memset(ptr->possible_positions[0], '\0', 100);
//	ptr->possible_positions[1] = ft_memset(ptr->possible_positions[0], '\0', 100);
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (check_possible_sol(ptr, i, j) == 1)
			{
				ptr->possible_positions[0][ptr->nb_sol] = j;
				ptr->possible_positions[1][ptr->nb_sol] = i;
				ptr->nb_sol++;
			}
			j++;
		}
		i++;
	}
}
