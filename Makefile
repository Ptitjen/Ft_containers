SRCS = srcs/main.cpp srcs/Chrono.cpp srcs/tests_utils.cpp

OBJS = ${SRCS:.cpp=.o}

NAME	= containers

RM	= @rm -f

CFLAGS = -Wall -Wextra -Werror

CC = clang++ -std=c++98 -fsanitize=address


all:	${NAME}		

$(NAME):	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}		

.cpp.o:
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
