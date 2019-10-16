/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:33:13 by dzboncak          #+#    #+#             */
/*   Updated: 2019/10/15 19:43:10 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_name(int fd)
{
	char	*name;

	lseek(fd, -(PROG_NAME_LENGTH + 8), SEEK_CUR);
	name = (char*)malloc(PROG_NAME_LENGTH + 4);
	read(fd, name, PROG_NAME_LENGTH + 4);
	return (name);
}

char	*read_comment(int fd)
{
	char	*comment;

	lseek(fd, 4, SEEK_CUR);
	comment = (char*)malloc(COMMENT_LENGTH + 4);
	read(fd, comment, COMMENT_LENGTH + 4);
	return (comment);
}

int		read_body(int fd, t_champion *champion)
{
	int		count_read;
	char	tmp[1];

	champion->body = (unsigned char*)malloc(champion->size);
	count_read = read(fd, champion->body, champion->size);
	if (count_read != champion->size)
		return (0);
	count_read = read(fd, tmp, 1);
	if (count_read != 0 && champion->size != 0)
		return (0);
	return (1);
}
