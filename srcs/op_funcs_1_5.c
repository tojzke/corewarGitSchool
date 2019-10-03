/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs_1_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:43:10 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/23 20:43:11 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void    live_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
    int     val;

    val = (int)get_value_from_battlefield(rules, cursor->position, OP_SIZE,
            g_op_tab[cursor->code_operation].dir_size);
    // Макс тут BYTES_BEFORE_ARGS заменил на OP_SIZE так как live не имеет кода типа
    // Или можно использовать функцию get_arg, там я добавил проверку на этот случай
    if (val == cursor->reg[1]) // Возможно значение val нужно сравнивать со всеми живыми игроками
    							// и засчитывать живым соответсвующего игрока
    {
        rules->last_alive = -val;
        if (rules->name_winner != 0)
        	free(rules->name_winner);
        rules->name_winner = ft_strdup(cursor->name);
    }
    cursor->last_live_in_cycle = rules->number_cycle;
    ++(rules->number_live_of_ctd);
}

void    load_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	int             value;
	unsigned char   reg_to_write;
	int             offset;
	unsigned char   dir_size;

	offset = BYTES_BEFORE_ARGS;
	dir_size = g_op_tab[cursor->code_operation].dir_size;
	if (args_types[0] == DIR_CODE) // value - это просто число
    {
        value = (int)get_value_from_battlefield(rules, cursor->position, offset,
                dir_size);
        offset += dir_size;
    }
    else //IND_CODE - считать из адреса value 4 байта
    {
        value = cursor->position + (int)get_value_from_battlefield(rules, cursor->position, offset,
                IND_SIZE) % IDX_MOD;
        value = (int)get_value_from_battlefield(rules, value, 0, REG_SIZE);
        offset += IND_SIZE;
    }
	reg_to_write = (unsigned char)get_value_from_battlefield(rules, cursor->position, offset,
															 REG_CODE_SIZE);
    cursor->carry = ((cursor->reg[reg_to_write] = value) == 0) ? 1 : 0;
}

void    store_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	unsigned char	from;
	short 			to;

	from = (unsigned char)get_arg(rules, cursor, args_types, 0);
	to = (short)get_arg(rules, cursor, args_types, 1);
	if (args_types[1] == REG_CODE)
	{
		cursor->reg[to] = cursor->reg[from];
	}
	else // IND_CODE
	{
		to = cursor->position + to % IDX_MOD;
		set_value_in_battlefield(rules, to, REG_SIZE, cursor->reg[from]);
	}
}

void	add_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	unsigned char	first_reg;
	unsigned char	second_reg;
	unsigned char	reg_to_write;


	first_reg = get_arg(rules, cursor, args_types, 0);
	second_reg = get_arg(rules, cursor, args_types, 1);
	reg_to_write = get_arg(rules, cursor, args_types, 2);
	cursor->reg[reg_to_write] = cursor->reg[first_reg] + cursor->reg[second_reg];
	cursor->carry = (cursor->reg[reg_to_write] == 0) ? 1 : 0;
}

void	sub_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	unsigned char	first_reg;
	unsigned char	second_reg;
	unsigned char	reg_to_write;


	first_reg = get_arg(rules, cursor, args_types, 0);
	second_reg = get_arg(rules, cursor, args_types, 1);
	reg_to_write = get_arg(rules, cursor, args_types, 2);
	cursor->reg[reg_to_write] = cursor->reg[first_reg] - cursor->reg[second_reg];
	cursor->carry = (cursor->reg[reg_to_write] == 0) ? 1 : 0;
}
