/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:36:33 by bkiehn            #+#    #+#             */
/*   Updated: 2019/10/15 20:29:45 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		select_champion(t_champion **champions, int current_champion)
{
	if (current_champion > MAX_PLAYERS)
		return (0);
	while (champions[current_champion] == NULL)
	{
		current_champion++;
		if (current_champion > MAX_PLAYERS)
			return (0);
	}
	return (current_champion);
}

int		definition_color(t_champion **champions, int number_champion, int count)
{
	if (count == champions[number_champion]->position)
		ft_printf(champions[number_champion]->color);
	if (count == champions[number_champion]->size +
		champions[number_champion]->position)
	{
		ft_printf(NO_COLOR);
		number_champion = select_champion(champions, number_champion + 1);
	}
	return (number_champion);
}

void	print_battlefiled(t_rules *rules, t_champion **champions)
{
	int count;
	int number_champion;

	count = 0;
	number_champion = select_champion(champions, 1);
	while (count < MEM_SIZE)
	{
		if (number_champion != 0)
			number_champion = definition_color(champions,
					number_champion, count);
		ft_printf("%.2x", rules->battlefield[count]);
		if (((count + 1) % 32) == 0)
			ft_printf("\n");
		else if (((count + 1) % 2) == 0)
			ft_printf(" ");
		count++;
	}
}

/*
**  правки внесены для облегчения сравнивания дампов со стандартной вирт машиной
*/

void	print_dump(t_rules *rules)
{
	int count;

	count = 0;
	while (count < MEM_SIZE)
	{
		if ((count % 64) == 0) // 64 заменить на 32
		{
			if (count == 0)
				ft_putstr("0x0000 : ");
			else
				ft_printf("%#.4x : ", count);
		}
		ft_printf("%.2x ", rules->battlefield[count]); //убрать пробел
		if (((count + 1) % 64) == 0) // 64 заменить на 32
			ft_printf("\n");
//		else if (((count + 1) % 2) == 0)
//			ft_printf(" ");
		count++;
	}
}
