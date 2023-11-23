SRCDIR	= ./srcs/
SRCNAME	= main.c utils.c checkers.c calc.c operators.c
SRCS	= ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.SILENT:
.PHONY:		clean fclean re all
