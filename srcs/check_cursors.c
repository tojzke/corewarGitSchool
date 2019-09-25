/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksey <aleksey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:24:25 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/19 19:14:16 by aleksey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion*		delete_cursor(t_champion* del_cursor, t_champion** cursors)
{
	t_champion* cursor;
	t_champion* tmp;

	cursor = *cursors;
	tmp = cursor;
	if (del_cursor == *cursors)
	{
		*cursors = (*cursors)->next;
		free_cursor(&tmp);
		return *cursors;
	}
	while (cursor != del_cursor)
	{
		tmp = cursor;
		if (cursor == NULL)
			return 0; //Что то пошло не так, удаляемый курсор не найден
		cursor = cursor->next;
	}
	tmp->next = cursor->next;
	free_cursor(&cursor);
	return tmp->next;
}

void			check_cursors(t_champion** cursors, t_rules* rules)
{
	t_champion* cursor;

	cursor = *cursors;
	rules->number_check++;
	while (cursor)
	{
		if (rules->ctd <= 0 ||
		rules->number_cycle - cursor->last_live_in_cycle >= rules->ctd)
		{
			cursor = delete_cursor(cursor, cursors);
			rules->number_cursors--;
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
	// Можно было обойтись только входящим параметром rules но, так как
	// rules->cursors появился после всего этого написанного, что бы не ломать
	// код и голову просто добавилась последняя строчка "rules->cursors = *cursors";
}