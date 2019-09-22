/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:03:54 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/22 19:19:02 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int		is_valid_args_code(t_rules *rules, t_champion *cursor)
{
	unsigned char *args_code;

	args_code = rules->battlefield + cursor->position + 1; //  Переместиться на код типов аргументов
	if (allowed_args(cursor->code_operation, args_code))
	{

	}
	return (0);
}

int		is_valid_op(t_rules *rules,t_champion *cursor)
{
	if (cursor->code_operation == LIVE_OP ||
		cursor->code_operation == ZJMP_OP ||
		cursor->code_operation == FORK_OP ||
		cursor->code_operation == LFROK_OP) // Эти операции не имеют код типов аргументов
		{
			return (1);
		}
	else
	{
		if (is_valid_args_code(rules, cursor)) // Проверка кода типа аргументов
		{

		}
	}
	
		
}

/*
** Функция решения запуска команды
** Если аргументы невалидные - переместить каретку на указанные аргументы в коде типов
*/

void	exec_command(t_rules *rules, t_champion *cursor)
{
	if (is_valid_op(rules, cursor))
	{

	}
	else
	{
		skip_command(rules, cursor);
	}
	
}