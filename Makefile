# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/09/20 16:52:25 by aleksey          ###   ########.fr        #
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
	
re: fclean libare printfre
	gcc -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft  -L ./ft_printf_fd -lftprintf

libare:
	make -C $(LIBRARY) re

printfre:
	make -C $(PRINTF) re

