NAME = connect4

CC	=	cc
CFLAGS	=  -MMD -Wall -Wextra -Werror

LIB_FLAGS		= -L./libft

RM	=	rm -rf

HEADER			=	-Iincludes/ -Ilibft/includes/ -Ilibft/libft/
INCLUDE_LIB		= ./libft/libftprintf.a
VALGRIND 		= -O0 -g

SRCS = srcs/connect4.c srcs/grid.c srcs/utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

%.o: %.c
		${CC} $(HEADER) ${CFLAGS} -c $< -o $@ $(VALGRIND)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJS) $(INCLUDE_LIB) $(VALGRIND)
	echo "The $(NAME) has been build !"

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	echo "The $(NAME) has been deleted !"

re : fclean all

-include $(DEPS)
.PHONY: all clean fclean re
