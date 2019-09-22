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

//unsigned cahr*	is_valid_args_code(t_rules *rules, t_champion *cursor)
//{
//	unsigned char *args_code;
//	unsigned char* type_args;
//	int	status_check;
//
//	types_args = (unsigned char*)malloc(sizeof(unsigned char) *
//				g_op_tab[cursor->code_operation].number_arg)
	// выделяем память под массив типов аргументов
//
//	args_code = rules->battlefield + cursor->position + 1; //  Переместиться на код типов аргументов
//	status_check = allowed_args(cursor->code_operation, args_code, types_args)
//	count_byte_for_next_operation(type_args, rules, cursor);
//	if (status_check)
//	{
//		При проверке нам нужно ещё и запомнить коды аргументов
//		или сделать это отдельной функцией после проверки,
//		так же вычислить number_byte_for_next_operation
//
//		Функция проверки номера регистра если данный тип аргументов
//		предполагает наличие регистра в аргументах.
//		Если всё ок, вернуть массив типов аргументов.
//
//		return type_args;
//	}
//	free(type_args);
//	return (0);
//}
//
//int		is_valid_op(t_rules *rules,t_champion *cursor)
//{
//	unsigned char*		type_arg;
//	if (cursor->code_operation == LIVE_OP ||
//		cursor->code_operation == ZJMP_OP ||
//		cursor->code_operation == FORK_OP ||
//		cursor->code_operation == LFROK_OP) // Эти операции не имеют код типов аргументов
//		{
//			return (1);
//		}
//	else
//	{
//		type_arg = is_valid_args_code(rules, cursor)
//		if (type_arg) // Проверка кода типа аргументов
//		{
//			Функция выбора функции на исполнение команды
//		}
//		Сдвинуть каретку на	number_byte_for_next_operation
//	}
//
//
//}
//
///*
//** Функция решения запуска команды
//** Если аргументы невалидные - переместить каретку на указанные аргументы в коде типов
//*/

void	exec_command(t_rules *rules, t_champion *cursor)
{
	ft_printf("Здесь код валиации типов аргументов, аргументов, и исполнения"
		   "команды при успешной валидации\n");
//	if (is_valid_op(rules, cursor))
//	{
//
//	}
//	else
//	{
//		skip_command(rules, cursor);
//	}
	
}