/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:49:36 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 21:04:55 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

void	delete_map(t_info *gl)
{
	char	*str;
	char	**begin;

	str = *gl->map;
	begin = gl->map;
	while (str)
	{
		gl->map++;
		free(str);
		str = *gl->map;
	}
	free(begin);
}

void	delete_fig(t_info *gl)
{
	int		i;
	char	**begin;

	i = 0;
	begin = gl->fig;
	while (begin[i])
	{
		free(begin[i]);
		i++;
	}
	free(gl->fig);
}

void	fl_writer(t_info *gl, int fd)
{
	int		i;

	ft_putnbr_fd(gl->point->y, fd);
	write(fd, " ", 1);
	ft_putnbr_fd(gl->point->x, fd);
	write(fd, "\n", 1);
	i = 0;
	while (gl->enemy_w)
	{
		if (gl->enemy_w->previous)
			free(gl->enemy_w->previous);
		if (gl->enemy_w->next)
			gl->enemy_w = gl->enemy_w->next;
		else
		{
			free(gl->enemy_w);
			break ;
		}
	}
	gl->enemy_w = NULL;
	delete_map(gl);
	delete_fig(gl);
}
