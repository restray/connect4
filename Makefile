NAME = connect4

CC	=	cc
CFLAGS	=  -MMD -Wall -Wextra -Werror

LIB_FLAGS		= -L./libft

RM	=	rm -rf

INC			=	-Iincludes/ -Ilibft/includes/ -Ilibft/libft/
LIBFT		= ./libft/libftprintf.a
DEBUG 		= -O0 -g3

SRCS = 	connect4.c \
		grid.c \
		ia.c \
		win_cond.c\
		utils.c \
		get_first_player.c

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p $(dir $@)
		${CC} $(INC) ${CFLAGS} -c $< -o $@ $(DEBUG)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS) $(LIBFT) $(DEBUG)
	echo "The $(NAME) has been build !"

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_PATH)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	echo "The $(NAME) has been deleted !"

re: fclean 
	$(MAKE) all

test: $(NAME)
	./connect4 6 7

staf: $(LIBFT)
	$(CC) -Wall -Wextra $(INC) srcs/get_first_player.c $(LIBFT) && ./a.out

-include $(DEPS)
.PHONY: all clean fclean re staf test
