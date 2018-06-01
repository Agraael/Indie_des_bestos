##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC		=	g++ -dynamic

CPPFLAGS	+=	-W -Wall -Wextra -I./lib/src/ -I./Settings/

CPPFLAGS	+=	-std=c++14

IRRLICHTFLAGS += -I/usr/include/irrlicht/ -L/usr/X11R6/lib -L../../lib/Linux -lIrrlicht -lGL -lGLU -lXxf86vm -lXext -lX11

SOUND_FLAGS += -lIrrKlang -lirrKlang -pthread

NAME		=	grph

SRCS		=	lib/src/IrrlichtLib.cpp        \
                lib/src/LibEventManager.cpp \
			    Settings/settingsMenu.cpp        \
			    main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all :		$(OBJS)
		$(CC) $(CPPFLAGS) $(IRRLICHTFLAGS) $(SOUND_FLAGS) $(OBJS) -o $(NAME)

clean :
		rm -f $(OBJS)

fclean :	clean
		    rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
