/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:58:26 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/22 17:15:06 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct  s_data
{
	char	**map;
	char	**piece;
	int		map_height;
	int		map_width;
	int		player;
	char	c;
}               t_data;

void	ft_parse_info(char **input, t_data *ptr);

#endif
