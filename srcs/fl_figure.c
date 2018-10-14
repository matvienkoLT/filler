/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:23:56 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 21:17:20 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

#define MAP 	b->map
#define WDTH 	b->m_width
#define ROWS	b->m_rows

void	fl_map_size(char *str, t_info *gr)
{
	while (!ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '\0')
		return ;
	gr->m_rows = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	while (!ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '\0')
		return ;
	gr->m_width = ft_atoi(str);
}

int		fig_clear_case(t_info *b, char c)
{
	char	**fig;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fig = b->fig;
	while (i < b->f_rows)
	{
		if (fig[i][j] == '*')
			break ;
		else
			j++;
		if (j >= b->f_width)
		{
			j = 0;
			i++;
		}
	}
	return (c == 'i' ? i : j);
}

int		clear_way_enemy(t_info *b, int i, int j)
{
	int status;

	status = 0;
	if (j + 2 < WDTH && MAP[i][j + 1] == '.' && MAP[i][j + 2] == '.')
		status = 1;
	if (j - 2 >= 0 && MAP[i][j - 1] == '.' && MAP[i][j + 2] == '.')
		status = 1;
	if (i - 2 >= 0 && MAP[i - 1][j] == '.' && MAP[i][j + 2] == '.')
		status = 1;
	if (i + 2 < ROWS && MAP[i + 1][j] == '.' && MAP[i][j + 2] == '.')
		status = 1;
	return (status);
}
