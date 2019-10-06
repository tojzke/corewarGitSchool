/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:52:10 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/30 17:36:52 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int				get_arg(t_rules *rules, t_champion *cursor,
	unsigned char *t_args, int num_arg)
{
	int arg;
	int	offset;

	if (g_op_tab[cursor->code_operation].is_code_type_arg)
		offset = count_size_args(t_args, num_arg,
		cursor->code_operation) + BYTES_BEFORE_ARGS;
	else
		offset = count_size_args(t_args, num_arg,
		cursor->code_operation) + OP_SIZE;
	if (t_args[num_arg] == IND_CODE)
		arg = (int)get_value_from_battlefield(rules,
		cursor->position, offset, IND_SIZE);
	else if (t_args[num_arg] == DIR_CODE)
		arg = (int)get_value_from_battlefield(rules, cursor->position, offset,
		g_op_tab[cursor->code_operation].dir_size);
	else if (t_args[num_arg] == REG_CODE)
		arg = get_value_from_battlefield(rules, cursor->position, offset,
		REG_CODE_SIZE);
	return (arg);
}

unsigned int	get_value_from_battlefield(t_rules *rules,
	int position, int offset, int size)
{
	unsigned int	value;
	unsigned int	byte_value;
	int				byte_index;

    if (position < 0)
    {
        position = MEM_SIZE - (-(position % MEM_SIZE));
    }
	value = 0;
	byte_index = 0;
	while (byte_index < size)
	{
		byte_value = rules->battlefield[(position +
			offset + byte_index) % MEM_SIZE];
		value = value | (byte_value << ((size - byte_index - 1) * 8));
		++byte_index;
	}
	return (value);
}

void		set_value_in_battlefield(t_rules *rules, int position, int size, const void *value)
{
	unsigned char	*byte_value;
	int				byte_index;


	if (position < 0)
		position = MEM_SIZE - (-(position % MEM_SIZE));
	byte_index = 0;
	byte_value = (unsigned char*)value + size - 1;
	while (byte_index < size)
	{
		rules->battlefield[(position + byte_index) % MEM_SIZE] = *byte_value;
		++byte_index;
		--byte_value;
	}
}

void			print_bits(const size_t size, const void *ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;

	b = (unsigned char*)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_printf("%u", byte);
			--j;
		}
		--i;
	}
	ft_putchar('\n');
}
