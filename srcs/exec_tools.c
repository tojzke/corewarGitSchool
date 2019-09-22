///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   exec_tools.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/09/21 18:52:10 by dzboncak          #+#    #+#             */
///*   Updated: 2019/09/21 20:28:58 by dzboncak         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "corewar.h"
//#include "commands.h"
//
//int		is_bit_set(char num, int bit)
//{
//	return (1 == ((num >> bit) & 1));
//}
//
//void	print_bits(const size_t size, const void *ptr)
//{
//	unsigned char	*b;
//	unsigned char	byte;
//	int				i;
//	int				j;
//
//	b = (unsigned char*)ptr;
//	i = size - 1;
//	while (i >= 0)
//	{
//		j = 7;
//		while (j >= 0)
//		{
//			byte = (b[i] >> j) & 1;
//			ft_printf("%u", byte);
//			--j;
//		}
//		--i;
//	}
//	ft_putchar('\n');
//}
