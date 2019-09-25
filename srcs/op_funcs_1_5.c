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

    val = (int)get_value_from_battlefield(rules, cursor->position, BYTES_BEFORE_ARGS,
            g_op_tab[cursor->code_operation].dir_size);
    if (val == cursor->reg[1])
    {
        rules->last_alive = -val;
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
	unsigned int	to;

	from = (unsigned char)get_value_from_battlefield(rules, cursor->position, BYTES_BEFORE_ARGS, REG_CODE_SIZE);
	if (args_types[1] == REG_CODE)
	{
		to = (unsigned char)get_value_from_battlefield(rules, cursor->position,
				BYTES_BEFORE_ARGS + REG_CODE_SIZE, REG_CODE_SIZE);
		cursor->reg[to] = cursor->reg[from];
	}
	else // IND_CODE
	{
		to = cursor->position + (int)get_value_from_battlefield(rules, cursor->position,
				BYTES_BEFORE_ARGS + REG_CODE_SIZE, IND_SIZE) % IDX_MOD;
		set_value_in_battlefield(rules, to, REG_SIZE, cursor->reg[from]);
	}
}

void	add_func(t_rules *rules, t_champion *cursor, unsigned char *args_types)
{
	unsigned char	first_reg;
	unsigned char	second_reg;
	unsigned char	where_to_write;
	int 			offset;

	offset = BYTES_BEFORE_ARGS;
	first_reg = (unsigned char)get_value_from_battlefield(rules, cursor->position, offset, REG_CODE_SIZE);
	offset += REG_CODE_SIZE;
	second_reg = (unsigned
}
