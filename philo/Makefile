SRCS = sources/main.c \
	sources/philo.c \
	sources/write_state.c

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

