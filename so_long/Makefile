SRCS 		= 	main.c \
				window.c \
				hooks.c \
				image.c \
				get_map.c \
				map_handler.c \
				get_next_line.c \
				get_next_line_utils.c \
				error_handler.c \
				init.c \
				player_handler.c \
				player_movement.c \
				utils.c \
				collectibles.c

SRC			= 	$(addprefix $(DIR), $(SRCS))

DIR			= 	src/

OBJS 		= 	${SRC:.c=.o}

NAME 		= 	so_long

AR 			= 	ar rcs

GCC			= 	gcc

RM 			= 	rm -f

CFLAGS 		= 	-Wall -Wextra -Werror

MLX_PATH	= 	./mlx/

LBFT_PATH	= 	./libft/

FRAMLIBS	= 	-L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all: 		$(NAME)
			
.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -fsanitize=address -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean
			@$(MAKE) -C $(MLX_PATH) clean

fclean: 	clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY: 	all clean fclean re