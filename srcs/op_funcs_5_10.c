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

}