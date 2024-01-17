# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/01/17 13:18:06
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.23)

project(Libft LANGUAGES C)
add_library(Libft)

file(GLOB_RECURSE sources "sources/*.c" "sources/*.h" "includes/*.h")
target_sources(Libft PRIVATE "${sources}")

target_include_directories(Libft PRIVATE sources)
target_include_directories(Libft PUBLIC includes)