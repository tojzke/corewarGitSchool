/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:42:09 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/02 23:03:57 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			checkNumberChampion(int curentNumberChampion, t_rules* rules, t_champion** champions)
{
	if (curentNumberChampion < 1 || curentNumberChampion > 4)
		return 0; //Не возможный номер петуха
	if (rules->muchPlayer == 4)
		return 0; //Превышенно количество петухов
	rules->muchPlayer++;
	if (curentNumberChampion != 0 && champions[curentNumberChampion] != NULL)
		return 0; //Такой петух уже есть
	else if (curentNumberChampion != 0)
	{
		champions[curentNumberChampion] = ft_memalloc(sizeof(t_champion));
		champions[curentNumberChampion]->number = curentNumberChampion;
		champions[curentNumberChampion]->reg[1] = -curentNumberChampion;
	}

	return curentNumberChampion;
}


int			calcNumberChampion(int curentNumberChampion, t_rules* rules, t_champion** champions)
{
	if (curentNumberChampion != 0)
		return curentNumberChampion;
	if (rules->muchPlayer == 4)
		return 0; //Превышенно количество петухов
	rules->muchPlayer++;
	curentNumberChampion = 1;

	while (champions[curentNumberChampion] != NULL)
	{
		curentNumberChampion++;
	}
	
	champions[curentNumberChampion] = ft_memalloc(sizeof(t_champion));
	champions[curentNumberChampion]->number = curentNumberChampion;
	champions[curentNumberChampion]->reg[1] = -curentNumberChampion;
	return curentNumberChampion;
}

int		parseArg(int argc, char** argv, t_rules *rules, t_champion **champions)
{
	int arg;
	int fd;
	int	curentNumberChampion;


	arg = 1;
	while (arg < argc)
	{
		curentNumberChampion = 0;
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
				curentNumberChampion = checkNumberChampion(ft_atoi(argv[arg]), rules, champions);
				if (curentNumberChampion == 0)
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
				curentNumberChampion = calcNumberChampion(curentNumberChampion, rules, champions);
				if (curentNumberChampion == 0)
					return 0; //С номером петуха что-то не так
				createChampion(champions[curentNumberChampion], rules, fd);
			}
		}
		arg++;
	}
	return 1;
}

int 	main(int argc, char** argv) {
	t_rules* rules;
	t_champion* champions[5];

	rules = ft_memalloc(sizeof(t_rules));
	if (!parseArg(argc, argv, rules, champions))
		ft_printf("Oshibka nahuy, akuratnee\n");

}

