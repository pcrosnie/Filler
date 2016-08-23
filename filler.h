/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:58:26 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 16:13:38 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct  s_data
{
	char	**map;
	char	**piece;
	char	**possible_positions;
	int		piece_height;
	int		piece_width;
	int		map_height;
	int		map_width;
	int		player;
	int		a;
	int		b;
	char	c;
}               t_data;

void	ft_algo(t_data *ptr);
void	ft_parse_info(char **input, t_data *ptr);
void	ft_parse_map(char *line, t_data *ptr);
void	ft_parse_player(char *line, t_data *ptr);
void	ft_parse_piece(char *line, t_data *ptr);

#endif
