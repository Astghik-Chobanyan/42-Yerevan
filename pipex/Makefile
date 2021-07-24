SRCS	= $(shell find "." -name "*.c")
OBJS	= ${SRCS:.c=.o}
NAME	= pipex
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

${NAME} : ${OBJS}
	gcc ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean