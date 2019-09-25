/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:17:09 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/25 19:17:14 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void free_cursor(t_champion** cursor)
{
	if (cursor != 0 && *cursor != 0)
	{
		if ((*cursor)->name)
			free((*cursor)->name);
		if ((*cursor)->comment)
			free((*cursor)->comment);
		if ((*cursor)->body)
			free((*cursor)->body);
		if ((*cursor)->color)
			free((*cursor)->color);
		free(*cursor);
		*cursor = NULL;
	}
}

void	clean_memory(t_rules* rules, t_champion* cursors)
{
	t_champion*		tmp;

	if (rules != 0)
		free(rules);
	while (cursors)
	{
		tmp = cursors;
		free_cursor(&cursors);
		cursors = tmp->next;
	}
}

void	end_game(int reason, t_rules* rules, t_champion* cursors)
{
	if (reason == PRINTING_DUMP)
		print_dump(rules);
	clean_memory(rules, cursors);
}