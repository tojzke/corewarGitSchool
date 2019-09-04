/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:36:33 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/04 22:05:51 by bkiehn           ###   ########.fr       */
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

int		select_champion(t_champion** champions, int start)
{
	while (champions[start] == NULL)
		start++;
	return start;
}

void	print_battlefiled(t_rules* rules, t_champion** champions)
{
	int count;
	int	interval;
	int champion;

	count = 0;
	champion = select_champion(champions, 1);
	interval = MEM_SIZE / rules->much_players;
	while (count < MEM_SIZE) 
	{
		if (count == 0 || count % interval == 0)
		{
			ft_printf(RED);
		}
		ft_printf("%.2x", rules->battlefield[count]);
		count++;
		ft_printf("%.2x", rules->battlefield[count]);
		if (((count + 1) % 32) == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
		if (count == champions[champion]->size)
		{
			ft_printf(NO_COLOR);
			champion = select_champion(champions, champion + 1);
		}
		count++;
	}
	ft_printf("\n");
}