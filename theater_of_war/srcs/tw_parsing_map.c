/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:10:56 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:34:12 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"

void			render_element(t_screen *scr)
{
	SDL_SetRenderDrawColor(scr->render, 0, 0, 0, 255);
	SDL_RenderClear(scr->render);
	tw_grid_draw(scr);
	if (scr->button && scr->lst->next->map[0])
		scr->lst = scr->lst->next;
	if (!scr->lst->next->map[0])
	{
		if (scr->lst->score_x > scr->lst->score_o)
			render_winner(scr, scr->player1, "WINNER: ");
		else if (scr->lst->score_x < scr->lst->score_o)
			render_winner(scr, scr->player0, "WINNER: ");
		else
			render_winner(scr, ".:", "DEAD HEAT:.");
		SDL_RenderCopy(scr->render, scr->winner, NULL, &(scr->name));
	}
	SDL_RenderCopy(scr->render, scr->texture, NULL, &(scr->dst));
	SDL_RenderCopy(scr->render, scr->name_players0, NULL, &(scr->name0));
	SDL_RenderCopy(scr->render, scr->name_players1, NULL, &(scr->name1));
	SDL_RenderCopy(scr->render, scr->score_players0, NULL, &(scr->s_o));
	SDL_RenderCopy(scr->render, scr->score_players1, NULL, &(scr->s_x));
	SDL_RenderPresent(scr->render);
}

static int		tw_map_rows(void)
{
	int		val;
	char	*temp;
	char	*str;

	val = -1;
	while (get_next_line(0, &temp))
	{
		if ((str = ft_strstr(temp, "Plateau ")))
		{
			while (!ft_isdigit(*str) && *str != '\0')
				str++;
			val = ft_atoi(str);
			free(temp);
			break ;
		}
		free(temp);
	}
	return (val);
}

static void		tw_map_repletion(char **map, int size)
{
	char	*temp;
	int		i;

	i = 1;
	while (i < size && get_next_line(0, &temp))
	{
		if (!(ft_strstr(temp, "Piece")))
		{
			map[i] = ft_strdup(temp + 4);
			i++;
		}
		free(temp);
	}
	map[i] = NULL;
}

static void		tw_score_players(t_screen *scr, char *temp, t_lmap *lst)
{
	if (ft_strstr(temp, "<got (X"))
	{
		lst->score_x = scr->score_x;
		lst->score_o = scr->score_o;
		scr->score_x++;
	}
	else if (ft_strstr(temp, "<got (O"))
	{
		lst->score_x = scr->score_x;
		lst->score_o = scr->score_o;
		scr->score_o++;
	}
}

void			tw_maps_list(t_screen *scr)
{
	char	*temp;
	t_lmap	*lst;

	if (scr->rows == -1)
		scr->rows = tw_map_rows();
	scr->lst = tw_create_element(scr->lst, scr->rows);
	lst = scr->lst;
	while (get_next_line(0, &temp))
	{
		if (ft_strstr(temp, "000 "))
		{
			scr->lst->map[0] = ft_strdup(temp + 4);
			tw_map_repletion(scr->lst->map, scr->rows);
			scr->lst->next = tw_create_element(scr->lst->next, scr->rows);
			scr->lst->next->behind = scr->lst;
			scr->lst = scr->lst->next;
		}
		else if (scr->lst->behind)
			tw_score_players(scr, temp, scr->lst);
		free(temp);
	}
	scr->lst = lst;
}
