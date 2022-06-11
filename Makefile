NAME = connect4

CC	=	cc
CFLAGS	=  -MMD -Wall -Wextra -Werror

LIB_FLAGS		= -L./libft

RM	=	rm -rf

INC			=	-Iincludes/ -Ilibft/includes/ -Ilibft/libft/
INCLUDE_LIB		= ./libft/libftprintf.a
DEBUG 		= -O0 -g3

SRCS = 	connect4.c \
		grid.c \
		utils.c

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
		@mkdir -p $(dir $@)
		${CC} $(INC) ${CFLAGS} -c $< -o $@ $(DEBUG)

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDE_LIB)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS) $(INCLUDE_LIB) $(DEBUG)
	echo "The $(NAME) has been build !"

$(INCLUDE_LIB):
	$(MAKE) -C ./libft

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_PATH)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	echo "The $(NAME) has been deleted !"

re : fclean 
	$(MAKE) all

-include $(DEPS)
.PHONY: all clean fclean re
