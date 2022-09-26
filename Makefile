SRCSFT = srcs/mainFt.cpp srcs/tests_utils/chrono_mono.cpp srcs/tests_utils/tests_utils.cpp

SRCSSTD = srcs/mainStd.cpp srcs/tests_utils/chrono_mono.cpp srcs/tests_utils/tests_utils.cpp

OBJSFT = ${SRCSFT:.cpp=.o}

OBJSSTD = ${SRCSSTD:.cpp=.o}

NAMEFT	= ft_containers

NAMESTD	= std_containers

RM	= @rm -f

CFLAGS = -Wall -Wextra -Werror

CC = c++ -std=c++98 

all:	${NAMEFT}	${NAMESTD}	

$(NAMEFT):	${OBJSFT}
			@${CC} ${CFLAGS} ${OBJSFT} -o ${NAMEFT}		

$(NAMESTD):	${OBJSSTD}
			@${CC} ${CFLAGS} ${OBJSSTD} -o ${NAMESTD}	

.cpp.o:
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	${RM} ${OBJSFT} ${OBJSSTD}

fclean:	clean
	${RM} ${NAMEFT} ${NAMESTD}

re:	fclean all
