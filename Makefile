# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegro <mnegro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 11:21:10 by mnegro            #+#    #+#              #
#    Updated: 2023/11/15 10:52:12 by mnegro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### PHONY TARGET ###
.PHONY: all clean fclean libft re

### SILENT TARGET ###
.SILENT:

### VARIABLES (DEFINITION) ###
NAME = cub3d
NAME_ARC = libftcub3d.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

MLXFLAGS = -lmlx -lXext -lX11 -lm
#### TARGETS ####
FL_SRCS = calcMap.c calcMapUtils.c checkMap.c checkTex.c \
			DDA.c drawMap.c handleEnds.c handleSprites.c \
			initDDA.c initMap.c initMapUtils.c initMLX.c \
			initVars.c loopMap.c main.c movePlayer.c rotPlane.c
DIRSRCS = src/
SRCS = ${addprefix ${DIRSRCS},${FL_SRCS}}

FL_OBJS = ${FL_SRCS:.c=.o}
DIROBJS = obj/
OBJS = ${addprefix ${DIROBJS},${FL_OBJS}}

INCLUDE = ./cub3d.h

MLX = minilibx-linux

DIRARC = arc/
ARC = ${addprefix ${DIRARC},${NAME_ARC}}

### (EXPLICIT) RULES ###
${DIROBJS}%.o: ${DIRSRCS}%.c
	@echo "${YELLOW}Compiling:${WHITE} $< ${DEF_COLOR}"
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: libft ${OBJS}
	cp libft/arc/libft.a ${ARC}
	${CC} ${CFLAGS} ${OBJS} -I {MLX} -I {INCLUDE} -L ${MLX} ${MLXFLAGS} -o ${NAME} ${ARC}
	@echo "Rule '${GREEN}all${DEF_COLOR}' for mandatory ${NAME} executed successfully!"

all:	${NAME}

clean:
	${MAKE} -C libft clean
	${RM} ${OBJS}
	@echo "Rule '${GREEN}clean${DEF_COLOR}' for ${NAME} executed successfully!"

fclean:
	${MAKE} -C libft fclean
	${RM} ${OBJS} ${NAME} ${ARC}
	@echo "Rule '${GREEN}fclean${DEF_COLOR}' for ${NAME} executed successfully!"

libft:
	${MAKE} -C libft

test: all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp  ./minishell

re:	fclean all
	@echo "Rule '${GREEN}re${DEF_COLOR}' for ${NAME} executed successfully!"

### (BRIGHT) COLORS ###
DEF_COLOR = \033[0;39m
BLACK = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m
