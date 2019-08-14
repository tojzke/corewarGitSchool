/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:22:13 by aleksey           #+#    #+#             */
/*   Updated: 2019/08/14 21:43:24 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BLACK		\033[30m
# define RED        \033[31m
# define GREEN      \033[32m
# define YELLOW     \033[33m
# define BLUE     	\033[34m
# define VIOLET     \033[35m
# define CYAN      	\033[36m

# include "../libft/includes/libft.h"
# include "ft_printf.h"
# include "op.h"
# include "unistd.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct 		s_rules
{
	int				dump;
	int 			numberPlayer;
	int				nextNumberPlayer;
	char			battlefield[MEM_SIZE];
}					t_rules;

typedef struct		s_champion
{
	int				number;
	char*			name;
	int				reg[REG_NUMBER + 1];
	int				size;
	struct corewar* next;
	
}					t_champion;


#endif