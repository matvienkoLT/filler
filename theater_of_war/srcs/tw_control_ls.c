/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_control_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:58:50 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/22 13:24:05 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"

t_lmap	*tw_create_element(t_lmap *element, int size)
{
	t_lmap *box;

	box = NULL;
	if (!element)
	{
		if (!(box = (t_lmap*)malloc(sizeof(t_lmap))))
			return (NULL);
		else
		{
			box->next = NULL;
			box->behind = NULL;
			box->score_o = 0;
			box->score_x = 0;
			box->map = (char**)malloc(sizeof(char*) * (size + 1));
			*box->map = NULL;
			if (!box->map)
				return (NULL);
		}
	}
	return (box);
}
