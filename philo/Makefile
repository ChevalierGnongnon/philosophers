SRCS = sources/main.c \
	sources/parse.c \
	sources/state.c \
	sources/utils.c 
	
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = philo

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:  
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)
	
re: fclean all

all: $(NAME)

.PHONY: all clean fclean re

