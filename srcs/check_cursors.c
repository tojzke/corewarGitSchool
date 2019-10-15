/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:24:25 by aleksey           #+#    #+#             */
/*   Updated: 2019/10/15 19:21:36 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_cursor(t_champion *del_cursor, t_champion **cursors)
{
	t_champion *current;
	t_champion *prev;

	current = *cursors;
	if (*cursors == del_cursor)
	{
		*cursors = (*cursors)->next;
		ft_memdel((void**)&current);
		return ;
	}
	while (current != NULL && current != del_cursor)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	ft_memdel((void**)&current);
}

void	check_cursors(t_champion **cursors, t_rules *rules)
{
	t_champion *cursor;

	cursor = *cursors;
	rules->number_check++;
	while (cursor)
	{
		if (rules->ctd <= 0 ||
		rules->number_cycle - cursor->last_live_in_cycle >= rules->ctd)
		{
			delete_cursor(cursor, cursors);
			rules->number_cursors--;
			cursor = *cursors;
		}
		else
			cursor = cursor->next;
	}
	if (rules->number_live_of_ctd >= NBR_LIVE ||
			MAX_CHECKS == rules->number_check)
	{
		rules->ctd -= CYCLE_DELTA;
		rules->number_check = 0;
	}
	rules->number_live_of_ctd = 0;
	rules->cursors = *cursors;
}
