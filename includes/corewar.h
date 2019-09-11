/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:22:13 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/11 21:24:03 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BLACK		"\033[30m"
# define RED        "\033[31m"
# define GREEN      "\033[32m"
# define YELLOW     "\033[33m"
# define BLUE     	"\033[34m"
# define VIOLET     "\033[35m"
# define CYAN      	"\033[36m"
# define NO_COLOR	"\033[m"

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
	int				much_players;
	unsigned char	battlefield[MEM_SIZE];
	int				last_alive;
}					t_rules;

typedef struct		s_champion
{
	int				number;
	int				fd;
	char*			name;
	char*			comment;
	unsigned char*	body;
	int				reg[REG_NUMBER + 1];
	int				size;
	int				position;
	char*			color;
	//struct corewar* next;
	
}					t_champion;

int					createChampion(t_champion* champion, t_rules* rules, int fd);
void 				print_bytes_hex(unsigned char* bytes, int size);
void				create_battlefield(t_rules* rules, t_champion** champions);
void				print_battlefiled(t_rules* rules, t_champion** champions);
int					select_champion(t_champion** champions, int current_champion);


#endif