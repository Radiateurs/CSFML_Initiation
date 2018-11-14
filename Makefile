#
# Magnificent Makefile made by Pierre-Marie
# 
# Compile the wonderfull project of C Graph Prog
#

CC =		gcc

RM =		rm -rf

# Links the include path
# Links the CSFML library.
# Available modules:
#	-lcsfml-window
#	-lcsfml-graphics
#	-lcsfml-system
#	-lcsfml-audio
#	-lcsfml-network
LDFLAGS =	-lcsfml-window -lcsfml-graphics

# Add the error compiling flags.
CFLAGS = 	-W -Wall -Werror -I./include/

NAME =		not_a_virus

SRCS =		src/main.c		\
		src/framebuffer.c	\
		src/pixels.c		\
		src/line.c		\
		src/rectangle.c

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all $(NAME) clean fclean re
