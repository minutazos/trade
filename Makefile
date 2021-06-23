##
## EPITECH PROJECT, 2020
## trade
## File description:
## makefile
##

CC			=	g++

RM			=	rm -f

NAME		=	trade

CXXFLAGS	=	-Wall
CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	-std=c++14
CXXFLAGS	+=	-I./include -g

SRC			=	src/main.cpp \
				src/Candles.cpp \
				src/Pair.cpp \
				src/Wallet.cpp \
				src/Settings.cpp \
				src/Bot.cpp

OBJ			=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re