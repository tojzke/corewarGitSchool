/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:42:09 by aleksey           #+#    #+#             */
/*   Updated: 2019/08/15 22:19:36 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		createChampion(t_champion* champions, t_rules* rules, int fd)
{	
	int*	tmp;
	int		hex;
	int		count;
	
	count = 4;
	hex = 0;
	tmp = (int*)malloc(sizeof(int));
	while (count--)
	{
		read(fd, tmp, 1);
		hex += *tmp << (count * 8);
		*tmp = 0;
	}
	if (hex != COREWAR_EXEC_MAGIC)
		return 0; //Засланый казачёк

	if ((lseek(fd, PROG_NAME_LENGTH + 4, SEEK_CUR)) == -1L)
		return 0; //Внутри казачка пустота
	count = 4;
	int size = 0;
	while (count--)
	{
		read(fd, tmp, 1);
		size += *tmp << (count * 8);
		*tmp = 0;
	}
	if (size > CHAMP_MAX_SIZE)
		return 0; //Жирный казачёк

	lseek(fd, -(PROG_NAME_LENGTH + 8), SEEK_CUR);
	char* name;
	name = (char*)malloc(PROG_NAME_LENGTH + 4);
	read(fd, name, PROG_NAME_LENGTH + 4);
	
	lseek(fd, 4, SEEK_CUR);
	char* comment;
	comment = (char*)malloc(COMMENT_CHAR + 4);
	read(fd, comment, COMMENT_CHAR + 4);

	ft_printf("%s\n", name);
	ft_printf("%s\n", comment);
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

