NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
		srcs/ft_utils.c \
		srcs/ft_flags.c \
		srcs/ft_flags_parser.c \
		srcs/ft_flag_c.c \
		srcs/ft_flag_s.c \
		srcs/ft_flag_p.c \
		srcs/ft_flag_pourcentage.c \
		srcs/ft_flag_u.c \
		srcs/ft_flag_x.c \
		srcs/ft_flag_i.c

D_LIBFT = libft/
D_SRCS = srcs/
INCLUDES = -Iincludes/ -Ilibft/

OBJS := ${patsubst %.c, %.o, ${SRCS}}

CC = cc
CFLAGS = -Wall -Werror -Wextra

all :		$(NAME)

$(NAME) :	${OBJS}
	$(MAKE) all -C $(D_LIBFT)
	cp libft/libft.a $(NAME)
	ar -crs ${NAME} ${OBJS}

clean :
	$(MAKE) clean -C $(D_LIBFT)
	rm -f ${OBJS}

fclean :	clean
	$(MAKE) fclean -C $(D_LIBFT)
	rm -f ${NAME}

re :		fclean all

%.o : %.c
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re
