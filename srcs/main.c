/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:42:09 by aleksey           #+#    #+#             */
/*   Updated: 2019/08/14 23:07:33 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		createChampion(t_champion* champions, t_rules* rules, int fd)
{	
	int	*source;
	
	source = (int*)malloc(4);
	read(fd, source, 1);
	printf("%x", *source);
	return 1;
}

int		parseArg(int argc, char** argv, t_rules *rules, t_champion *champions)
{
	int arg;
	int fd;

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
				rules->nextNumberPlayer = ft_atoi(argv[arg]);
			else
				return 0; //ошибка юзача
		}
		else
		{
			if ((fd = open(argv[arg], O_RDONLY)) == -1)
				return 0; //ошибка открытия файла
			else
				createChampion(champions, rules, fd);
		}
		arg++;
	}
	return 1;
}

int 	main(int argc, char** argv) {
	t_rules *rules;
	t_champion *champions;

	rules = ft_memalloc(sizeof(t_rules));
	if (!parseArg(argc, argv, rules, champions))
		ft_printf("Oshibka nahuy, akuratnee");

}

