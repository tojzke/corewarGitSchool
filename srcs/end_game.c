/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:17:09 by bkiehn            #+#    #+#             */
/*   Updated: 2019/10/15 19:57:09 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void	free_cursor(t_champion **cursor)
{
	if (cursor != 0 && *cursor != 0)
	{

		free(*cursor);
		*cursor = NULL;
	}
}

void	clean_memory(t_rules *rules, t_champion **cursors)
{
	t_champion *cursor;

	cursor = *cursors;
	while (rules->number_cursors != 0)
	{
		delete_cursor(cursor, cursors);
		rules->number_cursors--;
		cursor = *cursors;
	}
}


void	end_game(int reason, t_rules *rules, t_champion *cursors)
{
	if (reason == PRINTING_DUMP)
		print_dump(rules);
	if (reason == GAME_OVER)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", rules->last_alive,
		rules->name_winner);
//		print_rules(rules);
	}
//	clean_memory(rules, cursors);
	exit(0);
}
