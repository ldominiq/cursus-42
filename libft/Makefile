# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:43:57 by ldominiq          #+#    #+#              #
#    Updated: 2021/10/13 18:14:25 by ldominiq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c  \
			  ft_memset.c  \
			  ft_bzero.c   \
			  ft_memcpy.c  \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c  \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c  \
			  ft_memcmp.c  \
			  ft_strnstr.c \
			  ft_atoi.c    \
			  ft_strlcat.c \
			  ft_calloc.c  \
			  ft_strdup.c  \
			  ft_substr.c

OBJS 		= ${SRCS:.c=.o}

NAME 		= libft.a

AR 			= ar rc

RM 			= rm -f

FLAGS 		= -Wall -Wextra -Werror

all: 		${NAME}

${NAME}: 	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
