SRCS		= ft_printf.c \
			  print_utils/ft_utils.c \
			  print_utils/ft_printchar.c \
			  print_utils/ft_printstr.c \
			  print_utils/ft_printdigit.c \
			  print_utils/ft_printaddress.c \
			  print_utils/ft_printunsigned.c \

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
