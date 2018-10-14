/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_tops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:31:47 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 20:36:10 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

#define X lst->x
#define Y lst->y

void	fl_tops(t_info *box)
{
	if (box->player == 1)
	{
		if (!box->enemy_w)
			box->enemy_w = enemy_tops(box, 'X');
		fl_mforces(box, 'O');
	}
	else if (box->player == 2)
	{
		if (!box->enemy_w)
			box->enemy_w = enemy_tops(box, 'O');
		fl_mforces(box, 'X');
	}
}
