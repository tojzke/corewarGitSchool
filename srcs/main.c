/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:44:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/20 22:13:27 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "corewar.h"

void		error_msg(int err_code)
{
	ft_putendl(error_tab[err_code]);
	exit(err_code);
}

int			calcNumberChampion(t_rules* rules, t_champion** champions)
{
	int		currentNumberChampion;

	currentNumberChampion = 1;
	while (champions[currentNumberChampion] != NULL)
	{
		currentNumberChampion++;
	}


	return currentNumberChampion;
}

int		parseArg(int argc, char** argv, t_rules *rules, t_champion **champions)
{
	int arg;
	int fd;
	int	current_num;

	if (!all_valid(argc, argv, champions, rules))
		return (0);
	arg = 1;
	current_num = 0;
	while (arg < argc)
	{	
		if (ft_strequ(argv[arg], "-dump"))
		{
			arg++;
			if (arg <= argc)
				rules->dump = ft_atoi(argv[arg]);
			else
				return 0; //ошибка юзача
		}
		else if (ft_strequ(argv[arg], "-n"))
			arg += 2;
		else
		{
			if ((fd = open(argv[arg], O_RDONLY)) == -1)
				return 0; //ошибка открытия файла
			else
			{
				if (current_num == 0)
					if ((current_num = calcNumberChampion(rules, champions)) == 0)
						return 0; //С номером петуха что-то не так
				if (!create_champion(champions, rules, fd, current_num))
					return 0; //Ошибка при создании разрушителя миров
				current_num = 0;
			}
		}
		arg++;
	}
	return 1;
}

void	set_rules(t_rules* rules, t_champion** champions)
{
    int current_champion;

    current_champion = 4;
    while (champions[current_champion] == NULL)
        current_champion--;
    rules->last_alive = current_champion;
	rules->name_winner = champions[current_champion]->name;
	rules->ctd = CYCLE_TO_DIE;
}

int 	main(int argc, char** argv) {
	t_rules		rules;
	t_champion**	champions;
	t_champion*     cursors;

	champions = ft_memalloc(sizeof(t_champion*) * 5);
	ft_memset(&rules, 0, sizeof(t_rules));
	rules.much_players = get_num_of_players(argc, argv);
	if (!parseArg(argc, argv, &rules, champions))
		error_msg(ERR_PARSE);
	if (rules.much_players != 0)
		set_rules(&rules, champions);
	else
	{
		ft_printf("Zdes budet usage\n");
		exit (0);
	}
	create_battlefield(&rules, champions);
	/*
	 * Исторически сложилось, что начал работать с массивом
	 * чемпионов и последнии параметры для них устанавливаются в
	 * creat_battlefield, но для удобства реализации процесса игры
	 * чемпионов нужно переделать в список, и обозвать их курсорами
	 * что делается в creat_cursor, но это всё теже структуры.
	 * number_cursor определяется здесь же
	 */
	cursors = create_cursor(champions, &rules);
//	print_rules(rules);
//	print_cursors(cursors, 1);
//  print_battlefiled(rules, champions);
	start_game(cursors, &rules, champions);
//	Печатать после старт гейма есть смысл только в функции end_game,
//	так как в завершении функции end_game, всё чистится
}

