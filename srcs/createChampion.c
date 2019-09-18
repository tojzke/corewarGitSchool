/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createChampion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:37:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/09/18 18:38:50 by aleksey          ###   ########.fr       */
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

void	select_color(t_champion* champion)
{
	if (champion->number == 1)
		champion->color = ft_strdup(RED);
	else if (champion->number == 2)
		champion->color = ft_strdup(GREEN);
	else if (champion->number == 3)
		champion->color = ft_strdup(BLUE);
	else if (champion->number == 4)
		champion->color = ft_strdup(YELLOW);
}

char*	readComment(int fd)
{
	char* comment;

	lseek(fd, 4, SEEK_CUR);
	comment = (char*)malloc(COMMENT_LENGTH + 4);
	read(fd, comment, COMMENT_LENGTH + 4);
	return comment;
}

int		readBody(int fd, t_champion* champion)
{
	int		count_read;
	char	tmp[1];			

	champion->body = (unsigned char*)malloc(champion->size);
	count_read = read(fd, champion->body, champion->size);
	if (count_read != champion->size)
		return 0; //Размер петуха несоответствует обещанному
	count_read = read(fd, tmp, 1);
	if (count_read != 0 && champion->size != 0)
		return 0; //Размер петуха несоответствует обещанному

	return 1;
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
	select_color(champion);
	
	if (!readBody(fd, champion))
		return 0; //Размер петуха несоответствует обещанному
	close(fd);
	return 1;
}
