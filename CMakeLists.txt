cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_CXX_STANDARD 14)

include_directories(ft_printf_fd/includes)
include_directories(includes)
include_directories(libft/includes)


set(SRC_LIST ${SRC_LIST} srcs/battlefield.c
        srcs/check_cursor_args.c
        srcs/check_cursors.c
        srcs/create_champion.c
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
        srcs/start_game.c
        srcs/check_args.c
        srcs/read_champion.c)


add_executable(corewar ${SRC_LIST})

add_subdirectory(ft_printf_fd)
target_link_libraries(corewar ftprintf)
add_subdirectory(libft)
target_link_libraries(corewar ft)

