/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursor_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:55:53 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/21 20:29:49 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

//  Например, 10 01 00 00 
// !Сначала зануляем биты, которые левее!
// На первой итерации i_arg = 1
//			args_code >> (OP_CODE_SIZE{8} - OP_CODE_OFFSET{2} * i_arg{1}) == 00 00 00 10
// На второй i_arg = 2
//			args_code >> (OP_CODE_SIZE{8} - OP_CODE_OFFSET{2} * i_arg{2}) == 00 00 00 01
int is_valid_arg(int op_code, unsigned char args_code, int arg_num)
{
	unsigned char single_arg_code;
	printBits(sizeof(char), &args_code);
	single_arg_code = args_code << ((arg_num - 1) * OP_CODE_OFFSET); // Занулить биты которые левее
	single_arg_code = single_arg_code >> ((arg_num - 1) * OP_CODE_OFFSET);
	printBits(sizeof(char), &single_arg_code);
	single_arg_code = single_arg_code >> (OP_CODE_SIZE - (OP_CODE_OFFSET * arg_num)); // Переместить
	printBits(sizeof(char), &single_arg_code);
}

int	allowed_args(int op_code, unsigned char args_code)
{
	int	i_arg;
	unsigned char single_arg_code;

	i_arg = 1;
	while (i_arg <= MAX_ARGS)
	{
		is_valid_arg(op_code,args_code, i_arg);
		++i_arg;
	}
}