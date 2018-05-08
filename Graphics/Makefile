##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC		=	g++ -dynamic

CPPFLAGS	+=	-W -Wall -Wextra -I./include/ -I./lib/src/

CPPFLAGS	+=	-std=c++14

IRRLICHTFLAGS += -I/usr/include/irrlicht/ -L/usr/X11R6/lib -L../../lib/Linux -lIrrlicht -lGL -lGLU -lXxf86vm -lXext -lX11

NAME		=	grph

SRCS		=	lib/src/IrrlichtLib.cpp        \
			    Menu/src/Menu.cpp        \
			    main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(IRRLICHTFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		    rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
