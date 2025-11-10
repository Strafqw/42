NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f
SRC_DIR     = .
OBJ_DIR     = obj
INCDIR      = .
SRCS        = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
              ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
              ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
              ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
              ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
              ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS  = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiteri.c \
              ft_lstmap.c
OBJS       = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)
# Colors for pretty output
GREEN       = \033[0;32m
BLUE        = \033[0;34m
RESET       = \033[0m
all: $(NAME)
$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)✓ libft.a created$(RESET)"
bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)✓ libft.a created with bonus$(RESET)"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"
fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Library removed$(RESET)"
re: fclean all