/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:42:09 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/03 21:41:14 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			checkNumberChampion(int currentNumberChampion, t_rules* rules, t_champion** champions)
{
	if (currentNumberChampion < 1 || currentNumberChampion > 4)
		return 0; //Не возможный номер петуха
	if (rules->muchPlayer == 4)
		return 0; //Превышенно количество петухов
	rules->muchPlayer++;
	if (champions[currentNumberChampion] != NULL)
		return 0; //Такой петух уже есть
	champions[currentNumberChampion] = ft_memalloc(sizeof(t_champion));
	champions[currentNumberChampion]->number = currentNumberChampion;
	champions[currentNumberChampion]->reg[1] = -currentNumberChampion;

	return currentNumberChampion;
}


int			calcNumberChampion(t_rules* rules, t_champion** champions)
{
	int		currentNumberChampion;

	if (rules->muchPlayer == 4)
		return 0; //Превышенно количество петухов
	rules->muchPlayer++;
	currentNumberChampion = 1;

	while (champions[currentNumberChampion] != NULL)
	{
		currentNumberChampion++;
	}
	
	champions[currentNumberChampion] = ft_memalloc(sizeof(t_champion));
	champions[currentNumberChampion]->number = currentNumberChampion;
	champions[currentNumberChampion]->reg[1] = -currentNumberChampion;
	return currentNumberChampion;
}

int		parseArg(int argc, char** argv, t_rules *rules, t_champion **champions)
{
	int arg;
	int fd;
	int	currentNumberChampion;

	currentNumberChampion = 0;
	arg = 1;
	while (arg < argc)
	{	
		if (!ft_strcmp(argv[arg], "-dump"))
		{
			arg++;
			if (arg <= argc)
				rules->dump = ft_atoi(argv[arg]);
			else
				return 0; //ошибка юзача
		}
		else if (!ft_strcmp(argv[arg], "-n"))
		{
			arg++;
			if (arg <= argc)
			{
				currentNumberChampion = checkNumberChampion(ft_atoi(argv[arg]), rules, champions);
				if (currentNumberChampion == 0)
					return 0; //Что то не то с номером петуха
			}
			else
				return 0; //ошибка юзача
		}
		else
		{
			if ((fd = open(argv[arg], O_RDONLY)) == -1)
				return 0; //ошибка открытия файла
			else
			{
				if (currentNumberChampion == 0)
					if ((currentNumberChampion = calcNumberChampion(rules, champions)) == 0)
						return 0; //С номером пктуха что-то не так
				createChampion(champions[currentNumberChampion], rules, fd);
				currentNumberChampion = 0;
			}
		}
		arg++;
		ft_printf("------------------\n");
	}
	return 1;
}

int 	main(int argc, char** argv) {
	t_rules*		rules;
	t_champion**	champions;

	champions = ft_memalloc(sizeof(t_champion*) * 5);
	rules = ft_memalloc(sizeof(t_rules));
	if (!parseArg(argc, argv, rules, champions))
		ft_printf("%sOshibka nahuy, akuratnee%s\n", RED, NO_COLLOR);

}

