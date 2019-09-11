/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:36:33 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/11 21:46:20 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 	print_bytes_hex(unsigned char* bytes, int size)
{
	int count;

	count = 0;
	while (count < size) 
	{
		ft_printf("%.2x", bytes[count]);
		count++;
		ft_printf("%.2x", bytes[count]);
		if (((count + 1) % 32) == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
		count++;
	}
	ft_printf("\n");
}

int		select_champion(t_champion** champions, int current_champion)
{
	while (champions[current_champion] == NULL)
		current_champion++;
	return current_champion;
}

void	print_battlefiled(t_rules* rules, t_champion** champions)
{
	int count;
	int number_champion;

	count = 0;
	number_champion = select_champion(champions, 1);
	while (count < MEM_SIZE) 
	{
		if (count == champions[number_champion]->position)
			ft_printf(champions[number_champion]->color);
		if (count == champions[number_champion]->size + champions[number_champion]->position)
		{
			ft_printf(NO_COLOR);
			number_champion = select_champion(champions, number_champion + 1);
		}

		ft_printf("%.2x", rules->battlefield[count]);
		if (((count + 1) % 32) == 0)
			ft_printf("\n");
		else if (((count + 1) % 2) == 0)
			ft_printf(" ");
		count++;
	}
}