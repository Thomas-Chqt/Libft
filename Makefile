# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:24:59 by tchoquet          #+#    #+#              #
#    Updated: 2023/09/20 23:43:00 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_TYPE	= dynamic# static | dynamic
TARGET_TYPE	= release# release | debug

EXPORT_INCLUDE_DIR	= ${MY_C_INCLUDE_PATH}
EXPORT_LIB_DIR		= ${MY_LIBRARY_PATH}

ROOT				= .
SRCS_DIR			= ${ROOT}/sources
INCLUDES_DIR 		= ${ROOT}/includes
BUILD_DIR			= ${ROOT}/.build

EXPORT_INCLUDE	= ${EXPORT_INCLUDE_DIR}/libft.h
NAME_BASE 		= ${EXPORT_LIB_DIR}/libft


    SRC	= $(shell find ${SRCS_DIR} -type f -name '*.c')
    OBJ = $(foreach file, ${SRC:.c=.o}, ${BUILD_DIR}/$(notdir ${file}))
ifeq (${TARGET_TYPE}, debug)
    OBJ := ${OBJ:.o=_debug.o}
else ifneq (${TARGET_TYPE}, release)
    $(error Bad TARGET_TYPE)
endif


    CC			= cc
ifeq (${TARGET_TYPE}, release)
    CFLAGS		= -Wall -Wextra -Werror
else ifeq (${TARGET_TYPE}, debug)
    CFLAGS		= -g -D MEMCHECK -D DEBUG
else
    $(error Bad TARGET_TYPE)
endif
    CPPFLAGS	= -I${INCLUDES_DIR} -I${MY_C_INCLUDE_PATH}
    LDFLAGS		= -L${MY_LIBRARY_PATH}
    LDLIBS		= -l memory_leak_detector


ifeq (${TARGET_TYPE}, release)
    ifeq (${LIB_TYPE}, static)
        NAME = ${NAME_BASE}.a
    else ifeq (${LIB_TYPE}, dynamic) 
        NAME = ${NAME_BASE}.dylib
    else
        $(error Bad LIB_TYPE)
    endif
else ifeq (${TARGET_TYPE}, debug)
    ifeq (${LIB_TYPE}, static)
        NAME = ${NAME_BASE}_debug.a
    else ifeq (${LIB_TYPE}, dynamic) 
        NAME = ${NAME_BASE}_debug.dylib
    else
        $(error Bad LIB_TYPE)
    endif
else
    $(error Bad TARGET_TYPE)
endif


vpath %.c ${SRCS_DIR} ${SRCS_DIR}/ft_printf_utils

.PHONY: all clean fclean re


all: ${NAME} ${EXPORT_INCLUDE}

${NAME}: ${OBJ} | ${EXPORT_LIB_DIR}
ifeq (${LIB_TYPE}, static)
	@ar rc $@ $^
else
	@${CC} ${LDFLAGS} -dynamiclib -o $@ $^ ${LDLIBS}
endif
	@echo "Library created at $@"

${BUILD_DIR}/%_debug.o ${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ -c $<

${EXPORT_INCLUDE_DIR}/%.h: ${INCLUDES_DIR}/%.h | ${EXPORT_INCLUDE_DIR}
	@cp $< $@
	@echo "Include file copied at $@"

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."
	@rm -rf ${EXPORT_INCLUDE}
	@echo "${EXPORT_INCLUDE} deleted"

re: fclean all


#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created"

