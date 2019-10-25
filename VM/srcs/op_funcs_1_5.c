/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs_1_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:43:10 by dzboncak          #+#    #+#             */
/*   Updated: 2019/10/15 20:16:20 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	live_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	int	val;

	val = -(int)get_value_from_battlefield(rules, cursor->position + OP_SIZE,
		g_op_tab[cursor->code_operation].dir_size);
	if (val > 0 && val <= rules->much_players)
	{
		rules->last_alive = val;
		rules->name_winner = cursor->name;
	}
	cursor->last_live_in_cycle = rules->number_cycle;
	++(rules->num_live_of_ctd);
}

void	load_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	int		value;
	char	reg_to_write;

	value = get_arg(rules, cursor, args_types, 0);
	if (args_types[0] == IND_CODE)
		value = (int)get_value_from_battlefield(rules, cursor->position +
			(short)value % IDX_MOD, REG_SIZE);
	reg_to_write = (char)get_arg(rules, cursor, args_types, 1);
	cursor->reg[reg_to_write] = value;
	cursor->carry = (cursor->reg[reg_to_write] == 0) ? 1 : 0;
}

void	store_func(t_rules *rules,
		t_champion *cursor, unsigned char *args_types)
{
	char	from;
	int		to;

	from = (char)get_arg(rules, cursor, args_types, 0);
	to = get_arg(rules, cursor, args_types, 1);
	if (args_types[1] == REG_CODE)
		cursor->reg[(char)to] = cursor->reg[from];
	else
		set_value_in_battlefield(rules,
		cursor->position + (short)to % IDX_MOD, REG_SIZE, &(cursor->reg[from]));
}

void	add_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	char	first_reg;
	char	second_reg;
	char	reg_to_write;

	first_reg = (char)get_arg(rules, cursor, args_types, 0);
	second_reg = (char)get_arg(rules, cursor, args_types, 1);
	reg_to_write = (char)get_arg(rules, cursor, args_types, 2);
	cursor->reg[reg_to_write] = cursor->reg[first_reg]
								+ cursor->reg[second_reg];
	cursor->carry = (cursor->reg[reg_to_write] == 0) ? 1 : 0;
}

void	sub_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	char	first_reg;
	char	second_reg;
	char	reg_to_write;

	first_reg = (char)get_arg(rules, cursor, args_types, 0);
	second_reg = (char)get_arg(rules, cursor, args_types, 1);
	reg_to_write = (char)get_arg(rules, cursor, args_types, 2);
	cursor->reg[reg_to_write] = cursor->reg[first_reg]
								- cursor->reg[second_reg];
	cursor->carry = (cursor->reg[reg_to_write] == 0) ? 1 : 0;
}
