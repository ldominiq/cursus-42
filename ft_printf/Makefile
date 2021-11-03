SRCS 		= ft_printf.c main.c ft_utils.c

OBJS 		= ${SRCS:.c=.o}

NAME 		= libftprintf.a

AR 			= ar rcs

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

all: 		${NAME}

(OBJS):		%.o: %.c
			gcc -c $(CFLAGS) $< -o $@

${NAME}: 	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re