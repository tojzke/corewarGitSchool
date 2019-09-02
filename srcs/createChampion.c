/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createChampion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:37:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/02 21:29:00 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int checkMagicHeader(int fd)
{
	int		count;
	int*	tmp;
	int		hex;

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
	return 1;
}

int checkSizeChampion(int fd)
{
	int		count;
	int*	tmp;
	int 	size;

	tmp = (int*)malloc(sizeof(int));
	count = 4;
	size = 0;
	while (count--)
	{
		read(fd, tmp, 1);
		size += *tmp << (count * 8);
		*tmp = 0;
	}
	if (size > CHAMP_MAX_SIZE)
		return -1; //Жирный казачёк
	return size;
}

int		createChampion(t_champion* champion, t_rules* rules, int fd)
{	
	if (!checkMagicHeader(fd))
		return 0; //Засланый казачёк
	
	if ((lseek(fd, PROG_NAME_LENGTH + 4, SEEK_CUR)) == -1L)
		return 0; //Внутри казачка пустота
	
	if (checkSizeChampion(fd) == -1)
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
