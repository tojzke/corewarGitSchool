/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createChampion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:37:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/03 23:10:27 by bkiehn           ###   ########.fr       */
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

char*	readName(int fd)
{
	char* name;

	lseek(fd, -(PROG_NAME_LENGTH + 8), SEEK_CUR);
	name = (char*)malloc(PROG_NAME_LENGTH + 4);
	read(fd, name, PROG_NAME_LENGTH + 4);
	return name;
}

char*	readComment(int fd)
{
	char* comment;

	lseek(fd, 4, SEEK_CUR);
	comment = (char*)malloc(COMMENT_LENGTH + 4);
	read(fd, comment, COMMENT_LENGTH + 4);
	return comment;
}

char*		readBody(int fd, t_champion* champion)
{
	// char* body;

	// body = (char*)malloc(champion->size);
	// read(fd, body, champion->size);
	// return body;
	
	int		count;
	int*	tmp;
	int		hex;

	count = champion->size;
	hex = 0;
	tmp = (int*)malloc(sizeof(int));

	while (count--)
	{
		read(fd, tmp, 1);
		// hex += *tmp << (count * 8);
		ft_printf("%d (%x); ", *tmp, *tmp);
		// *tmp = 0;
	}
	ft_printf("\n");
	return "zdes budet telo petuha";
}

int		createChampion(t_champion* champion, t_rules* rules, int fd)
{	
	if (!checkMagicHeader(fd))
		return 0; //Засланый казачёк
	
	if ((lseek(fd, PROG_NAME_LENGTH + 4, SEEK_CUR)) == -1L)
		return 0; //Внутри казачка пустота
	
	if ((champion->size = checkSizeChampion(fd)) == -1)
		return 0; //Жирный казачёк

	champion->name = readName(fd);
	champion->comment = readComment(fd);
	champion->fd = fd;
	champion->body = readBody(fd, champion);

	
	
	

	ft_printf("name: %s\n", champion->name);
	ft_printf("comment: %s\n", champion->comment);
	ft_printf("number: %d\n", champion->number);
	ft_printf("size: %d\n", champion->size);
	ft_printf("body: %s\n", champion->body);
	return 1;
}
