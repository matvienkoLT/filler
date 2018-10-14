/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:04:23 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 21:13:15 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

static void	fl_fig_size(char *p_str, t_info *gr)
{
	char	*str;

	str = p_str;
	while (!ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '\0')
		return ;
	gr->f_rows = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	while (!ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '\0')
		return ;
	gr->f_width = ft_atoi(str);
	free(p_str);
}

static void	fl_player(t_info *gl, int fd)
{
	char	*line;
	char	*str;
	int		status;

	if ((status = get_next_line(fd, &line)) != 1)
		return ;
	else
	{
		str = line;
		while (*str != 'p' && *str != '\0')
			str++;
		gl->player = *(++str) - '0';
		free(line);
	}
}

static char	**fl_margin_pic(int fd, size_t r)
{
	char	*line;
	char	**margin;
	size_t	i;

	i = 0;
	margin = (char**)malloc(sizeof(char*) * (r + 1));
	while (i < r && get_next_line(fd, &line) == 1)
	{
		margin[i] = line;
		i++;
	}
	margin[i] = NULL;
	return (margin);
}

static char	**fl_margin(int fd, size_t r)
{
	char	*line;
	char	**margin;
	size_t	i;

	i = 0;
	margin = (char**)malloc(sizeof(char*) * (r + 1));
	get_next_line(fd, &line);
	free(line);
	while (i < r && get_next_line(fd, &line) == 1)
	{
		margin[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	margin[i] = NULL;
	return (margin);
}

int			fl_reader(int fd, t_info *gr)
{
	int		status;
	char	*fl_data;

	if (!gr->player)
		fl_player(gr, fd);
	if ((status = get_next_line(fd, &fl_data)) != 1)
		return (0);
	if (!gr->m_width || !gr->m_rows)
	{
		fl_map_size(fl_data, gr);
		free(fl_data);
	}
	gr->map = fl_margin(fd, gr->m_rows);
	if (!(status = get_next_line(fd, &fl_data)))
		return (0);
	fl_fig_size(fl_data, gr);
	gr->fig = fl_margin_pic(fd, gr->f_rows);
	return (1);
}
