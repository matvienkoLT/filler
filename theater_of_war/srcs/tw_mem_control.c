/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_mem_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:46:34 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:44:50 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"

static void	map_clear(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void		tw_mem_cleaner(t_screen *scr)
{
	scr->lst = scr->c_lst;
	while (scr->lst)
	{
		map_clear(scr->lst->map);
		scr->lst = scr->lst->next;
	}
	free(scr->player0);
	free(scr->player1);
	SDL_DestroyTexture(scr->texture);
	SDL_DestroyTexture(scr->name_players0);
	SDL_DestroyTexture(scr->name_players1);
	SDL_DestroyTexture(scr->score_players0);
	SDL_DestroyTexture(scr->score_players1);
	if (scr->winner)
		SDL_DestroyTexture(scr->winner);
	SDL_FreeSurface(scr->surface);
}
