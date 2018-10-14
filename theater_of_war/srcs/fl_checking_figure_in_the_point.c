/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_checking_figure_in_the_point.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:49:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 20:03:17 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

#define I PNT->i_f
#define J PNT->j_f
#define MAP b->map
#define FIG b->fig
#define PNT b->point
#define M_I b->point->i
#define M_J b->point->j

static int	check_correlation_fig(t_info *b, int n1, int k)
{
	int n;

	n = n1;
	while (J - n >= 0)
	{
		if (M_J - n < 0 || M_I + k < 0 || M_I + k >= b->m_rows)
			return (0);
		if (FIG[I + k][J - n] == '*' && MAP[M_I + k][M_J - n] != '.')
			return (0);
		n++;
	}
	n = n1;
	while (J + n < b->f_width)
	{
		if (M_J + n >= b->m_width || M_I + k < 0 || M_I + k >= b->m_rows)
			return (0);
		if (FIG[I + k][J + n] == '*' && MAP[M_I + k][M_J + n] != '.')
			return (0);
		n++;
	}
	return (1);
}

static int	ck_fig_v_lft(t_info *b, int n)
{
	while (I + n < b->f_rows)
	{
		if (FIG[I + n][J] == '*')
		{
			if ((M_I + n >= b->m_rows || MAP[M_I + n][M_J] != '.'))
				return (0);
		}
		if (!check_correlation_fig(b, 1, n))
			return (0);
		n++;
	}
	return (1);
}

int			ck_fig_v_r(t_info *b, int n)
{
	if (!check_correlation_fig(b, 1, 0))
		return (0);
	while (I - n >= 0)
	{
		if ((M_I - n < 0 || (FIG[I - n][J] == '*' && MAP[M_I - n][M_J] != '.')))
			return (0);
		if (!check_correlation_fig(b, 1, -n))
			return (0);
		n++;
	}
	if (!ck_fig_v_lft(b, 1))
		return (0);
	return (1);
}
