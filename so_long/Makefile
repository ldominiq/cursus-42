SRCS 		= 

OBJS 		= ${SRCS:.c=.o}

NAME 		= mlx.a

AR 			= ar rcs

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

all: 		${NAME}

%.o: %.c
			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

.c.o:
			gcc -c $(CFLAGS) $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re