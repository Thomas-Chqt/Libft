# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:24:59 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/11 21:02:54 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT				= .
SRCS_DIR			= ${ROOT}/sources
FT_PRINTF_SRC_DIR	= ${SRCS_DIR}/ft_printf_utils
INCLUDES_DIR 		= ${ROOT}/includes
BUILD_DIR			= ${ROOT}/.build

EXPORT_INCLUDE_DIR	= ${MY_C_INCLUDE_PATH}
EXPORT_LIB_DIR		= ${MY_LIBRARY_PATH}

SRC		= ${wildcard ${SRCS_DIR}/*.c} ${wildcard ${FT_PRINTF_SRC_DIR}/*.c}
EXE_SRC	= ${ROOT}/main_for_test.c

RELEASE_OBJ = ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${patsubst ${FT_PRINTF_SRC_DIR}%, ${BUILD_DIR}%, ${SRC:.c=.o}}}
DEBUG_OBJ	= ${RELEASE_OBJ:.o=_debug.o}
EXE_OBJ		= ${patsubst ${ROOT}%, ${BUILD_DIR}%, ${EXE_SRC:.c=.o}}

CC						= gcc
CFLAGS					= -Wall -Wextra -Werror
debug debugexe: CFLAGS	= -g -D MEMCHECK
EXTERNAL_LIBS			= -l memory_leak_detector

NAME			= ${EXPORT_LIB_DIR}/libft.a
EXPORT_INCLUDE	= ${EXPORT_INCLUDE_DIR}/libft.h
DEBUG_LIB		= ${EXPORT_LIB_DIR}/libft_debug.a
DEBUG_EXE		= ${ROOT}/Debug.out

vpath %.c ${ROOT} ${SRCS_DIR} ${FT_PRINTF_SRC_DIR}

.PHONY: all clean fclean re debug cleandebug fcleandebug redebug debugexe fcleandebugexe fcleandebugexe redebugexe norm cleanbuild


all: ${NAME} ${EXPORT_INCLUDE}

${NAME}: ${RELEASE_OBJ} | ${EXPORT_LIB_DIR}
	@ar rc $@ $^
	@echo "Archive created at $@."

clean:
	@rm -rf ${RELEASE_OBJ}
	@echo "Release object files deleted."

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."
	@rm -rf ${EXPORT_INCLUDE}
	@echo "${EXPORT_INCLUDE} deleted."

re: fclean all





debug: ${DEBUG_LIB} ${EXPORT_INCLUDE}

${DEBUG_LIB}: ${DEBUG_OBJ} | ${EXPORT_LIB_DIR}
	@ar rc $@ $^
	@echo "Archive created at $@."

cleandebug:
	@rm -rf ${DEBUG_OBJ}
	@echo "Debug object files deleted."

fcleandebug: cleandebug
	@rm -rf ${DEBUG_LIB}
	@echo "${DEBUG_LIB} deleted."
	
redebug: fcleandebug debug





debugexe: ${DEBUG_EXE}

${DEBUG_EXE}: ${DEBUG_OBJ} ${EXE_OBJ}
	@${CC} -o $@ $^ ${EXTERNAL_LIBS}
	@echo "Executable created at $@."

cleandebugexe: cleandebug
	@rm -rf ${EXE_OBJ}
	@echo "Object files for executable deleted."

fcleandebugexe: cleandebugexe
	@rm -rf ${DEBUG_EXE}
	@echo "${DEBUG_EXE} deleted."

redebugexe: fcleandebugexe debugexe






norm:
	@norminette ${SRCS_DIR} ${INCLUDES_DIR}


cleanbuild:
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted."



#All targets
${BUILD_DIR}/%_debug.o ${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

${EXPORT_INCLUDE_DIR}/%.h: ${INCLUDES_DIR}/%.h | ${EXPORT_INCLUDE_DIR}
	@cp $< $@
	@echo "Include file copied at $@."


#folders
${EXPORT_INCLUDE_DIR} ${EXPORT_LIB_DIR} ${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."

