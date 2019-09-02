# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/09/02 20:56:04 by bkiehn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

INC = ./includes

LIBAFERST = make -C $(LIBRARY)

LIBRARY = libft
	
$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) -I $(INC) -L ./$(LIBRARY) -lft -lftprintf

liba:
	make -C $(LIBRARY)

objs/%.o: srcs/%.c
	@gcc -c $< -o $@ -I $(INC)

debug:
	gcc -g3 -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft

clean:
	rm -f $(OBJS)
	make -C $(LIBRARY) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBRARY) fclean
	
re: fclean libare
	gcc -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft -lftprintf

libare:
	make -C $(LIBRARY) re
