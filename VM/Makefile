# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/10/01 19:24:03 by dzboncak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

INC = ./includes

LIBAFERST = make -C $(LIBRARY)

LIBRARY = libft

PRINTF = ft_printf_fd
	
$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) -I $(INC) -L ./$(LIBRARY) -lft -L ./ft_printf_fd -lftprintf

liba:
	make -C $(LIBRARY)

objs/%.o: srcs/%.c
	@mkdir -p objs
	@gcc -c $< -o $@ -I $(INC)

debug:
	gcc -g3 -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft -L ./ft_printf_fd -lftprintf

clean:
	rm -f $(OBJS)
	make -C $(LIBRARY) clean
	make -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBRARY) fclean
	make -C $(PRINTF) fclean
	
re: fclean libare printfre $(OBJS)
	gcc -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft  -L ./ft_printf_fd -lftprintf

libare:
	make -C $(LIBRARY) re

printfre:
	make -C $(PRINTF) re

## Diff arguments ##

# Write champs from stdin
## e.g CHAMPS = Batman.cor Gangnat.cor
CHAMPS =

# Dump
## e.g DUMP = 2000
DEF_DUMP_FLAG = -d
OURS_DUMP_FLAG = -dump
DUMP =

DEF_NAME = defcorewar
DEF_OUT = def.res
OURS_OUT = ours.res

diff_output: ##Usage: make diff_output DUMP=<dump_cycle> CHAMPS=<champs_arg>
ifeq ($(strip $(CHAMPS)),)
	@echo "No champs given"
	@echo "Result is incorrect"
endif
#Run with not given dump
ifeq ($(strip $(DUMP)),)
	$(addprefix ./,$(NAME)) $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
else
	$(addprefix ./,$(NAME)) $(OURS_DUMP_FLAG) $(DUMP)  $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(DEF_DUMP_FLAG) $(DUMP) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
endif	
## End Diff ##