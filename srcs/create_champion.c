/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:37:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/10/15 19:44:23 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_magic_header(int fd)
{
	int	count;
	int	*tmp;
	int	hex;

	count = 4;
	hex = 0;
	tmp = (int*)malloc(sizeof(int));
	while (count--)
	{
		read(fd, tmp, 1);
		hex += *tmp << (count * 8);
		*tmp = 0;
	}
	ft_memdel((void**)&tmp);
	if (hex != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

int		check_size_champion(int fd)
{
	int	count;
	int	*tmp;
	int	size;

	tmp = (int*)malloc(sizeof(int));
	count = 4;
	size = 0;
	while (count--)
	{
		read(fd, tmp, 1);
		size += *tmp << (count * 8);
		*tmp = 0;
	}
	ft_memdel((void**)&tmp);
	if (size > CHAMP_MAX_SIZE)
		return (-1);
	return (size);
}

void	select_color(t_champion *champion)
{
	if (champion->number == 1)
		champion->color = RED;
	else if (champion->number == 2)
		champion->color = GREEN;
	else if (champion->number == 3)
		champion->color = BLUE;
	else if (champion->number == 4)
		champion->color = YELLOW;
}

int		create_champion(t_champion **champions, t_rules *rules,
		int fd, int current_num)
{
	if (champions[current_num] != NULL)
		return (0);
	else
	{
		champions[current_num] = ft_memalloc(sizeof(t_champion));
		champions[current_num]->number = current_num;
		champions[current_num]->reg[1] = -current_num;
	}
	if (!check_magic_header(fd))
		return (0);
	if ((lseek(fd, PROG_NAME_LENGTH + 4, SEEK_CUR)) == -1L)
		return (0);
	if ((champions[current_num]->size = check_size_champion(fd)) == -1)
		return (0);
	champions[current_num]->name = read_name(fd, current_num);
	champions[current_num]->comment = read_comment(fd);
	champions[current_num]->fd = fd;
	select_color(champions[current_num]);
	if (!read_body(fd, champions[current_num]))
		return (0);
	close(fd);
	return (1);
}
