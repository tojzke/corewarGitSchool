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

void	and_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);
	if (t_args[0] == IND_CODE)
		arg1 = get_value_from_battlefield(rules, cursor->position,
				arg1 % IDX_MOD, REG_SIZE);
	else if (t_args[0] == REG_CODE)
		arg1 = cursor->reg[arg1];
	if (t_args[1] == IND_CODE)
		arg2 = get_value_from_battlefield(rules, cursor->position,
				arg2 % IDX_MOD, REG_SIZE);
	else if (t_args[1] == REG_CODE)
		arg2 = cursor->reg[arg2];
	cursor->reg[arg3] = arg1 & arg2;
	cursor->reg[arg3] == 0 ? cursor->carry = 1 : cursor->carry = 0;
}

void			or_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{

}