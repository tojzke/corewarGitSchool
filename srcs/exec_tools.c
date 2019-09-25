/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:52:10 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/21 20:28:58 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int		is_bit_set(char num, int bit)
{
	return (1 == ((num >> bit) & 1));
}

unsigned int	get_value_from_battlefield(t_rules *rules,
                                           int position, int offset, int size)
{
    unsigned int	value;
    unsigned int	byte_value;
    int				byte_index;

    value = 0;
    byte_index = 0;
    while (byte_index < size)
    {
        byte_value = rules->battlefield[(position + offset + byte_index) % MEM_SIZE];
//        printf("%d-th byte:%x\n", byte_index, byte_value);
        value = value | (byte_value << (byte_index * 8));
        ++byte_index;
    }
    return (value);
}

void		set_value_in_battlefield(t_rules *rules, int position, int size, int value)
{
	unsigned char	byte_value;
	int				byte_index;

	byte_index = 0;
	while (byte_index < size)
	{
		byte_value = 0;
		byte_value |= (value >> (byte_index * 8));
		rules->battlefield[(position + byte_index) % MEM_SIZE] = byte_value;
		++byte_index;
	}
}

void	print_bits(const size_t size, const void *ptr)
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
