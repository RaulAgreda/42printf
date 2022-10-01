LIBFT_SRCS	= libft/ft_strchr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c
LIBFT_OBJS 	= ${LIBFT_SRCS:.c=.o}
SRCS		= ft_printf.c ft_puthex_fd.c ft_putpointer_fd.c
OBJS		= ${SRCS:.c=.o}
BONUS		= a
BOBJS		= ${BONUS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
CC			= gcc
AR			= ar r
RM			= rm -rf
BONUS_RE 	= .

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT_OBJS}
			${AR} ${NAME} ${OBJS} ${LIBFT_OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${BONUS_RE}: ${BOBJS} ${OBJS}
# 			${AR} ${NAME} ${OBJS} ${BOBJS}

# bonus:  ${BONUS_RE}

normi: 
			norminette ${LIBFT_SRCS} ${SRCS}

clean:	
			${RM} ${OBJS} ${BOBJS} ${LIBFT_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus all
