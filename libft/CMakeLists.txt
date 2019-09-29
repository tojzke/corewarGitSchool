cmake_minimum_required(VERSION 3.14)
project(libft)

file (GLOB LIBFT_SRC
        "*.c")
file (GLOB LIBFT_HDRS
        "includes/*.h")

add_library(ft ${LIBFT_SRC})