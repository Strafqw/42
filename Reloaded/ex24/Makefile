# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 11:59:03 by lfrazao           #+#    #+#              #
#    Updated: 2025/10/16 12:40:45 by lfrazao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
SRCS_FILES	=	srcs/ft_putchar.c	srcs/ft_putstr.c	srcs/ft_strcmp.c	\
				srcs/ft_strlen.c	srcs/ft_swap.c
HEADER		=	./includes/
AR			=	ar rc
RM			=	rm -rf
OBJS		=	$(SRCS:srcs/%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADER)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re