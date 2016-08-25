/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:24:30 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/25 10:53:28 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_recup_piece_size(char *input, t_data *ptr)
{
	int i;
	int j;
	char *str;

	i = 6;
	j = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	j = 0;
	ptr->piece_height = ft_atoi(str);
	str = ft_memset(str, '\0', 10);
	i++;
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	ptr->piece_width = ft_atoi(str);
	free(str);
}

char	*ft_str_cut(char *input)
{
	int i;
	int j;
	char *str;

	if (!input)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(input)));
	i = 4;
	j = 0;
	while (input[i])
	{
		str[j++] = input[i++];
	}
	str[j] = '\0';
	return (str);
}

void	ft_recup_map_size(char *input, t_data *ptr)
{
	int i;
	int j;
	char *str;

	i = 8;
	j = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	j = 0;
	ptr->map_height = ft_atoi(str);
	str = ft_memset(str, '\0', 10);
	i++;
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	ptr->map_width = ft_atoi(str);
	free(str);
}

void	ft_parse_player(char *line, t_data *ptr)
{
	if (ft_strstr(line, "exec p1 :") != NULL)
		ptr->c = 'O';
	if (ft_strstr(line, "exec p2 :") != NULL)
		ptr->c = 'X';
}

void	ft_parse_map(char *line, t_data *ptr)
{
	int i;

	i = 0;
	ft_recup_map_size(line, ptr);
	ptr->map = (char **)malloc(sizeof(char *) * (ptr->map_height + 3));
	while (i < ptr->map_height)
	{
		get_next_line(0, &line);
		ptr->map[i++] = ft_str_cut(line);
	}
	ptr->map[i] = NULL;
}

void	ft_cut_first_lines(t_data *ptr)
{
	int i;

	i = 0;
	free(ptr->piece[0]);
	while (i < ptr->piece_height)
	{
		ptr->piece[i] = ptr->piece[i + 1];
		i++;
	}
	ptr->piece_height--;
}

void	ft_cut_last_lines(t_data *ptr)
{
	int i;

	i = ptr->piece_height - 1;
	free(ptr->piece[i]);
	ptr->piece[i] = NULL;
	ptr->piece_height--;
}

int		ft_check_first_star(t_data *ptr)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = ptr->piece_width;
	while (i < ptr->piece_height)
	{
		while (j < ptr->piece_width)
		{
			if (ptr->piece[i][j] == '*' && j < tmp)
				tmp = j;
			j++;
		}
		i++;
	}
	return (tmp);
}

int		ft_check_last_star(t_data *ptr)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < ptr->piece_height)
	{
		j = 0;
		while (j < ptr->piece_width)
		{
			if (ptr->piece[i][j] == '*' && j > tmp)
				tmp = j;
			j++;
		}
		i++;
	}
	return (tmp + 1);
}

void	ft_cut_width(t_data *ptr, int start, int end)
{
	int i;
	int j;
	int k;
	char *tmp;

	i = 0;
	k = 0;
	j = start;
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	while (i < ptr->piece_height)
	{
		j = start;
		k = 0;
		tmp = ft_memset(tmp, '\0', end - start + 1);
		while (j < end)
		{
			tmp[k] = ptr->piece[i][j];
			k++;
			j++;
		}
		free(ptr->piece[i]);
		ptr->piece[i] = ft_strdup(tmp);
		i++;
	}
	ptr->piece_width = end - start;
}

void	ft_cut_piece(t_data *ptr)
{
//	int i;
	int j;

//	while (ft_strstr(ptr->piece[0], "*") == NULL)
//		ft_cut_first_lines(ptr);
	while (ft_strstr(ptr->piece[ptr->piece_height - 1], "*") == NULL)
		ft_cut_last_lines(ptr);
//	i = ft_check_first_star(ptr);
	j = ft_check_last_star(ptr);
	ft_cut_width(ptr, 0, j);
}

void	ft_parse_piece(char *line, t_data *ptr)
{
	int i;

	i = 0;
	ft_recup_piece_size(line, ptr);
	ptr->piece = (char **)malloc(sizeof(char *) * (ptr->piece_height + 3));
	while (i < ptr->piece_height)
	{
		get_next_line(0, &line);
		ptr->piece[i++] = ft_strdup(line);
	}
	ptr->piece[i] = NULL;
	ft_cut_piece(ptr);
//	ft_print_char_tab(ptr->piece);
}
