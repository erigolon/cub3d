
#  /Users/agil-ord/.brew/opt/glfw/lib 
#  /opt/homebrew/Cellar/glfw/3.3.8/lib/

NAME	= cub3D
LIBMLX	= ./libs/MLX42
LIBFT	= ./libs/libft
LIBGN	= ./libs/get_next_line


USER	= $(shell whoami)
HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN}
LIBGL	= -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBGN}/get_next_line.a



SRCS	= ./src/main.c \
			./src/cub3d_utils.c \
			./src/parser/check_file.c \
			./src/images.c \
			./src/move.c

OBJS	= ${SRCS:.c=.o}


all: libft libmlx libgn ${NAME}

libft:
	@${MAKE} -s -C ${LIBFT}

libmlx:
	@${MAKE} -s -C ${LIBMLX}

libgn:
	@${MAKE} -s -C ${LIBGN}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBGN} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBGN} fclean
	
re: clean all

.PHONY: all, clean, fclean, re