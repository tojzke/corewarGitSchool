cmake_minimum_required(VERSION 3.14)
project(ft_printf)

file(GLOB FTPRINTF_SRC
        "srcs/*.c")

file(GLOB FTPRINT_HDRS
        "includes/*.h")

add_library(ftprintf ${FTPRINTF_SRC})
