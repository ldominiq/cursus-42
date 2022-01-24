CLIENT			=	client

SERVER			=	server

SRC	 			=	server.c client.c

OBJS			=	$(SRC:.c=.o)

CC				= 	gcc

RM	 			= 	rm -f

CFLAGS	 		= 	-Wall -Wextra -Werror

LIBFT			=	libft/libft.a

LBFT_PATH		= 	./libft/

FT_PRINTF		= 	ft_printf/libftprintf.a

FT_PRINTF_PATH	=	./ft_printf/

all: 		$(SERVER) $(CLIENT)

$(LIBFT):	
			$(MAKE) -C $(LBFT_PATH)

$(FT_PRINTF):	
			$(MAKE) -C $(FT_PRINTF_PATH)

$(CLIENT): 	$(FT_PRINTF) $(LIBFT) client.o minitalk.h
			$(CC) -o client client.o $(LIBFT) $(FT_PRINTF)

$(SERVER): 	$(FT_PRINTF) $(LIBFT) server.o minitalk.h
			$(CC) -o server server.o $(LIBFT) $(FT_PRINTF)

clean:
			${RM} ${OBJS}
			$(MAKE) -C $(LBFT_PATH) clean
			$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: 	clean
			${RM} server client 
			$(MAKE) -C $(LBFT_PATH) fclean
			$(MAKE) -C $(FT_PRINTF_PATH) fclean

re:			fclean all

.PHONY: 	all clean fclean re