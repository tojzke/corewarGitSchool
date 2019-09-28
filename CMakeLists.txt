cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_CXX_STANDARD 14)

include_directories(ft_printf_fd/includes)
include_directories(ft_printf_fd/libft/includes)
include_directories(includes)
include_directories(libft/includes)

link_directories(libft)
link_directories(ft_printf_fd)

set(SRC_LIST ${SRC_LIST} srcs/battlefield.c
        srcs/check_cursor_args.c
        srcs/check_cursors.c
        srcs/createChampion.c
        srcs/cursors.c
        srcs/end_game.c
        srcs/exec_command.c
        srcs/exec_tools.c
        srcs/main.c
        srcs/op.c
        srcs/op_funcs_1_5.c
        srcs/op_funcs_6_10.c
        srcs/op_funcs_11_15.c
        srcs/op_func_16.c
        srcs/print.c
        srcs/start_game.c)

file(GLOB SRCFILES srcs/*.c)

add_executable(corewar ${SRC_LIST})

target_link_libraries(corewar ftprintf.a)
target_link_libraries(corewar libftprintf.a)

