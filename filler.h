/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:58:26 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/24 12:18:45 by pcrosnie         ###   ########.fr       */
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
	int		solX;
	int		solY;
	int		a;
	int		b;
	char	c;
}               t_data;

typedef	struct	s_pos
{
	int		my_posXmin;
	int		my_posYmin;
	int		my_posXmax;
	int		my_posYmax;
	int		adv_posXmax;
	int		adv_posYmax;
	int		adv_posXmin;
	int		adv_posYmin;
}				t_pos;

void	ft_algo(t_data *ptr);
void	ft_parse_map(char *line, t_data *ptr);
void	ft_parse_player(char *line, t_data *ptr);
void	ft_parse_piece(char *line, t_data *ptr);
void	ft_strat(t_data *ptr);
void	ft_recup_my_x(t_data *ptr, t_pos *e);
void	ft_recup_my_y(t_data *ptr, t_pos *e);
void	ft_recup_adv_x(t_data *ptr, t_pos *e);
void	ft_recup_adv_y(t_data *ptr, t_pos *e);

#endif
