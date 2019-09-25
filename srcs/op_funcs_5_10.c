/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs_5_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:52:00 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/25 20:52:03 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_arg(t_rules* rules, t_champion* cursor, unsigned char *t_args, int num_arg)
{
	int arg;
	int val;
	int	offset;

	offset = count_size_args(t_args, num_arg, int op_code) + BYTES_BEFORE_ARGS;
	if (t_args[num_arg] == IND_CODE)
	{
		arg = (int)get_value_from_battlefield(rules, cursor->position, offset, IND_SIZE);
		val = get_value_from_battlefield(rules, cursor->position, arg, REG_SIZE);
	}
	else if (t_args[num_arg] == DIR_CODE)
		val = get_value_from_battlefield(rules, cursor->position, offset,
										  g_op_tab[cursor->code_operation].dir_size);
	else if (t_args[num_arg] == REG_CODE)
	{
		arg = get_value_from_battlefield(rules, cursor->position, offset,
										  REG_CODE_SIZE);
		val = cursor->reg[arg];
	}

	return val;
}

void	and_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);

}