/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:39:02 by dzboncak          #+#    #+#             */
/*   Updated: 2019/10/15 19:07:04 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_num_of_players(int argc, char **argv)
{
	int	num;
	int	i;

	num = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump") || ft_strequ(argv[i], "-n"))
			i += 2;
		else
		{
			++num;
			++i;
		}
	}
	if (num > 4)
		return (0);
	return (num);
}

int		create_n_champ(char **argv, int argi,
		t_champion **champions, t_rules *rules)
{
	int fd;
	int current_num;
	int num_players;

	if ((fd = open(argv[argi + 2], O_RDONLY)) == -1)
		return (0);
	++argi;
	current_num = ft_atoi(argv[argi]);
	if (current_num <= 0
	|| current_num > rules->much_players
	|| champions[current_num] != NULL)
	{
		close(fd);
		ft_putendl("Use -n correctly!");
		return (0);
	}
	++argi;
	if (!create_champion(champions, rules, fd, current_num))
	{
		ft_printf("Something wrong with %s champion!\n", argv[argi]);
		return (0);
	}
	return (1);
}

int		valid_n_flags(int argc, char **argv,
		t_champion **champions, t_rules *rules)
{
	int i;
	int	fd;
	int current_num;

	i = 1;
	while (i < argc - 2)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			if (!create_n_champ(argv, i, champions, rules))
				return (0);
			i += 2;
		}
		++i;
	}
	return (1);
}

int		all_valid(int argc, char **argv, t_champion **champions, t_rules *rules)
{
	int num_players;

	if ((num_players = get_num_of_players(argc, argv)) == 0)
	{
		ft_putendl("Too many champs!");
		return (0);
	}
	if (!valid_n_flags(argc, argv, champions, rules))
		return (0);
	return (1);
}
