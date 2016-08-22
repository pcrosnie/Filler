/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:24:30 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/22 17:17:14 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_str_cut(char *input)
{
	int i;
	int j;
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(input) - 3));
	i = 4;
	j = 0;
	ft_putendl(input);
	while (input[i])
	{
		str[j++] = input[i++];
	}
	str[j] = '\0';
	return (str);
}

void	ft_recup_map(char **input, t_data *ptr)
{
	int i;
	int j;

	j = 2;
	i = 0;
	ptr->map = (char **)malloc(sizeof(char *) * (ptr->map_height + 1));
	while (i < ptr->map_height)
	{
		ft_putstr("XXXX");
		ft_putstr(input[j]);
		ptr->map[i++] = ft_str_cut(input[j++]);
	}
	ptr->map[i] = NULL;
}

void	ft_recup_piece(char **intput, t_data *ptr)
{
	int i;
	int j;

	j = 0;
	ptr->piece = (char **)malloc(sizeof(char *) * (ptr->map_height + 1));
	i = ptr->map_height + 2;
	while (intput[i])
		ptr->piece[j++] = ft_strdup(intput[i++]);
	ptr->piece[j] = NULL;
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
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	ptr->map_width = ft_atoi(str);
	free(str);
}

void	ft_parse_info(char **input, t_data *ptr)
{
	ft_recup_map_size(input[0], ptr);
	ft_recup_map(input, ptr);
	ft_recup_piece(input, ptr);
}
