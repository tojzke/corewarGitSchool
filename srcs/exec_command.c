/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:03:54 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/23 18:34:23 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int		count_size_args(unsigned char* type_args, int how_many_arg, int op_code)
{

}

int		check_arg_reg(t_rules* rules, t_champion* cursor,
		unsigned char* type_args)
{
	int				count;
	int				offset;
	unsigned char	arg_reg;

	count = 0;
	while(count < g_op_tab[cursor->code_operation].number_arg)
	{
		if (type_args[count] == REG_CODE)
		{
			offset = count_size_args(type_args, count, cursor->code_operation) + BYTES_BEFORE_ARGS;
			/*
			 * count_size_args подсчёт байт занимаемых аргументами до reg аргумента
			 */
			arg_reg = (unsigned char)get_value_from_battlefield(rules, cursor->position, offset,
					sizeof(unsigned char));
			if (arg_reg < 1 || arg_reg > MAX_REG)
				return 0
		}
		count++;
	}
	return 1;
}

int		is_valid_op(t_rules *rules,t_champion *cursor, unsigned char* type_args)
{
	unsigned char	args_code;
	int				status_check;

	num_arg_reg = 0;
	if (g_op_tab[cursor->code_operation].is_code_type_arg == 0)
	// Операция не имеет кода типов аргументов, и аргумента T_REG
		return (1);
	else
	{
		args_code = (unsigned char)get_value_from_battlefield(rules, cursor->position, OP_SIZE,
															  sizeof(unsigned char));
		// Переместиться на код типов аргументов, для перемещения каретки
		// нужно напсиать отдельную функцию так как память циклическая
		// и возможны перехды на на начало поля
		status_check = allowed_args(cursor->code_operation, args_code, types_args);
		// Проверка кода тип аргументов
		if (status_check)
			status_check = check_arg_reg(rules, cursor, type_args);
			// Проверка регистра
		count_byte_for_next_operation(type_args, rules, cursor);
	}
	return status_check;

}

/*
** Функция решения запуска команды
** Если аргументы невалидные - переместить каретку на указанные аргументы в коде типов
*/

void	exec_command(t_rules *rules, t_champion *cursor)
{
	ft_printf("Здесь код валиации типов аргументов, аргументов, и исполнения"
		   "команды при успешной валидации\n");
	unsigned char*		type_args;
	type_args = (unsigned char*)malloc(sizeof(unsigned char) *
				g_op_tab[cursor->code_operation].number_arg);
	// выделяем память под массив типов аргументов
	if (is_valid_op(rules, cursor, type_args))
	{
		//			Функция выбора функции на исполнение команды
		// g_func_tab[cursor->code_operation](rules, cursor, type_args)
	}
	free(type_args);
	skip_command(rules, cursor);
	//Сдвинуть каретку на number_byte_for_next_operation
}