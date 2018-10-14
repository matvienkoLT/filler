/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:29:39 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 17:51:43 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

t_cord	*create_lst(t_info *lst)
{
	t_cord *block;

	if (!(block = (t_cord*)malloc(sizeof(t_cord))))
		return (NULL);
	block->next = NULL;
	block->previous = NULL;
	block->x = lst->m_width;
	block->y = lst->m_rows;
	block->written = 0;
	return (block);
}

t_cord	*find_elem(t_cord *block, int *i, int *j, t_info *lst)
{
	if (block->written)
	{
		block->next = create_lst(lst);
		block->next->previous = block;
		block = block->next;
	}
	block->x = *j;
	block->y = *i;
	block->written = 1;
	return (block);
}

t_cord	*enemy_tops(t_info *lst, char c)
{
	char	**box;
	int		i[2];
	t_cord	*block;
	t_cord	*begin;

	box = lst->map;
	i[0] = 0;
	i[1] = 0;
	if (!(block = create_lst(lst)))
		return (NULL);
	begin = block;
	while (box[i[0]])
	{
		if (box[i[0]][i[1]] == c && clear_way_enemy(lst, i[0], i[1]))
			block = find_elem(block, &i[0], &i[1], lst);
		else if (box[i[0]][i[1]] == '\n' || box[i[0]][i[1]] == '\0')
		{
			i[0]++;
			i[1] = 0;
			continue;
		}
		i[1]++;
	}
	return (begin);
}
