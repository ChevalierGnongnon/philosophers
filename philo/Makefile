FILES = atoi \
	free \
	main \
	parse \
	routine \
	state \
	time \
	utils 

SRC = $(foreach f, $(FILES), sources/$(f).c)

OBJS = $(foreach f, $(FILES), objects/$(f).o)

CC = cc

CFLAGS = -Werror -Wextra -Wall -g3

NAME = philo

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objects/%.o: sources/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:  
	rm -rf objects

fclean: clean
	rm -f $(NAME)
	
re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
