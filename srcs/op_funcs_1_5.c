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

void    ld_func(t_rules *rules, t_champion *cursor, unsigned char *args_types) {
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
        reg_to_write = (int)get_value_from_battlefield(rules, cursor, offset,
                REG_SIZE);
        cursor->carry = ((cursor->reg[reg_to_write] = value) == 0) ? 1 : 0;
    }
    else if (args_types[0] == IND_CODE) // считать из адреса value 4 байта
    {
        value = cursor->position + (int)get_value_from_battlefield(rules, cursor, offset,
                IND_SIZE) % IDX_MOD;
        value = (int)get_value_from_battlefield(rules, value, 0, REG_SIZE);
        offset += IND_SIZE;
        reg_to_write = (unsigned char)get_value_from_battlefield(rules, cursor, offset,
                    REG_SIZE);
        cursor->carry = ((cursor->reg[reg_to_write] = value) == 0) ? 1 : 0;
    }
}
