##
## Makefile for Rtype in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
##
## Made by julien edmond
## Login   <edmond_j@epitech.net>
##
## Started on  Thu Oct 24 14:08:19 2013 julien edmond
## Last update Mon Oct 28 16:57:17 2013 julien edmond
##

NAME=		server

SRC=		RType/main.cpp \
		RType/WinThread.cpp \
		RType/UnixThread.cpp \
		RType/WinMutex.cpp \
		RType/UnixMutex.cpp \
		RType/UnixCondVar.cpp

OBJ=		$(SRC:.cpp=.o)

IPATH=		-I RType

CXXFLAGS=	-Wall -Wextra -Werror $(IPATH) -lpthread

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
