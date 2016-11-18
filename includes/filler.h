/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:58:26 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/15 15:05:04 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

/* strat :  1 = va au centre ; 2 = trace ligne de blocage a centre + 1 ; 3 remplit partie adverse; 
 * 4 remplit sa partie;*/

typedef struct  s_data
{
	char	**map;
	char	**piece; /* [0] -> x [1] -> y*/
	char	**possible_positions;
	int		sol_index;
	int		piece_height;
	int		piece_width;
	int		first_posx; /*a soustraire avant de print */
	int		first_posy;
	int		res_index;
	int		map_height;
	int		map_width;
	int		player;
	int		solX;
	int		solY;
	int		a;
	int		b;
	char	c;
	int		strat;
	int		ref_line;
	int		set_vert;
	int		part;  /*0 en haut : 1 en bas */
	int		nb_sol;
	int		center;				/* center = 1 > me center = 2 > adv*/
}               t_data;

void	ft_check_possible_positions(t_data *ptr);
void	ft_output(int a, int b);
void	ft_reach_center(t_data *ptr);
void	ft_algo(t_data *ptr);
void	ft_parse_map(char *line, t_data *ptr);
void	ft_parse_player(char *line, t_data *ptr);
void	ft_parse_piece(char *line, t_data *ptr);
void	ft_strat(t_data *ptr);

#endif
