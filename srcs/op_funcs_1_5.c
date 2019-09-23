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

void    live_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
    int     val;
    int     offset;

    val = (int)get_value_from_battlefield(rules, cursor->position, BYTES_BEFORE_ARGS, g_op_tab[cursor->code_operation].dir_size);

    if (val == cursor->reg[1])
    {
        rules->last_alive = -val;
    }
    cursor->last_live_in_cycle = rules->number_cycle;
    ++(rules->number_live_of_ctd);
}

void    ld_
