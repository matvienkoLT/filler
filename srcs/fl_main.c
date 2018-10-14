/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:37:44 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:30:02 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

static void	initially_intended(t_info *step)
{
	step->player = 0;
	step->f_rows = 0;
	step->f_width = 0;
	step->m_rows = 0;
	step->m_width = 0;
	step->fig = NULL;
	step->map = NULL;
	step->enemy_w = NULL;
	step->point->way = 9999;
	step->point->x = -1;
	step->point->y = -1;
}

static void	initially_end(t_info *step)
{
	step->f_rows = 0;
	step->f_width = 0;
	step->m_rows = 0;
	step->m_width = 0;
	step->fig = NULL;
	step->map = NULL;
	step->point->way = 9999;
	step->point->x = -1;
	step->point->y = -1;
	step->point->i_f = 0;
	step->point->j_f = 0;
	step->point->i = 0;
	step->point->j = 0;
}

int			main(void)
{
	int		i;
	int		status;
	t_info	step;
	t_point	point;

	i = 0;
	step.point = &point;
	initially_intended(&step);
	while (1)
	{
		status = fl_reader(0, &step);
		fl_tops(&step);
		if (step.point->way == 9999)
			break ;
		fl_writer(&step, 1);
		initially_end(&step);
		i++;
	}
	return (0);
}
