/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksey <aleksey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:02:24 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/19 17:32:58 by aleksey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	introduction(t_champion** champions, t_rules* rules)
{
	int             current_champion;
	int             count;

	current_champion = 0;
	count = 0;
	ft_printf("Introducing contestants...\n");
	while (++count <= rules->much_players)
	{
		current_champion = select_champion(champions, current_champion);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				champions[current_champion]->number,
				champions[current_champion]->size,
				champions[current_champion]->name,
				champions[current_champion]->comment);
		current_champion++;
	}
}

void	start_game(t_champion* cursors, t_rules* rules, t_champion** champions)
{
	introduction(champions, rules);
	int ctd;
	t_champion* cursor;

	ctd = rules->ctd;
	cursor = cursors;
	while (rules->number_cursors)
	{

		while (cursor)
		{
			//view cursor
			cursor = cursor->next;
		}
		ctd--;
		rules->number_cycle++;
		if (ctd <= 0)
		{
			check_cursors(&cursors, rules);
			ctd = rules->ctd;
		}
	}



}