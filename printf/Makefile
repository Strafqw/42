NAME        = libftprintf.a

SRCS        = ft_printf.c \
              ft_putstr.c \
              ft_putnbr.c \
              ft_putnbr_base.c \
              ft_putchar.c \
              ft_handleformat.c \
			  ft_pp.c

OBJS        = $(SRCS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
