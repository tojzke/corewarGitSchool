/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:22:13 by aleksey           #+#    #+#             */
/*   Updated: 2019/09/20 16:55:12 by aleksey          ###   ########.fr       */
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

typedef struct 			s_rules
{
	int					dump;
	int					number_cursors;		//количество кареток
	int					much_players;		//количество игроков
	unsigned char		battlefield[MEM_SIZE];
	int					last_alive;        //последний прокукарекавший петух
	int					number_cycle;     //Количество циклов с начала игры
	int					number_live_of_ctd; //Количество выполненых операций live за CYCLE_TO_DIE
	int					ctd;				//CYCLE_TO_DIE - длительность периода до проверки
	int					number_check;		//Количество проведёных проверок
}						t_rules;

typedef struct			s_champion
{
    int             	number_cursors;
	int					number;       //номер игрока
	int					fd;
	char*				name;
	char*				comment;
	unsigned char*		body;
	int					reg[REG_NUMBER + 1];
	int					size;			//рзмер тела в байтах
	int					position;  //позиция на поле боя
	char*				color;
	int					carry;
	int					code_operation;
	int					last_live_in_cycle;
	int					cycle_before_run;
	int					number_byte_for_next_operation;
	void				(*to_string)(struct s_champion* cursor, char flag_body);
	struct s_champion* 	next;
}						t_champion;

int						createChampion(t_champion* champion, t_rules* rules, int fd);
void 					print_bytes_hex(unsigned char* bytes, int size);
void					create_battlefield(t_rules* rules, t_champion** champions);
void					print_battlefiled(t_rules* rules, t_champion** champions);
int						select_champion(t_champion** champions, int current_champion);
t_champion*				create_cursor(t_champion** champions, t_rules* rules);
void					print_cursors(t_champion* cursor, char flag_body);
void					to_string(t_champion* cursors, char flag_body);
						/*
						 * flag_body == 1 body print
						 * flag_body == 0 body no print
						 */
void					print_rules(t_rules* rules);
void					start_game(t_champion* cursors, t_rules* rules,
									t_champion** champions);
t_champion*				add_cursor_in_start(t_champion* cursors,
									   		t_champion* champion);
void					check_cursors(t_champion** cursors, t_rules* rules);


#endif