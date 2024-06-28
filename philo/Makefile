FILES = free \
	main \
	parse \
	state \
	utils 

SRC = $(foreach f, $(FILES), sources/$(f).c)

OBJS = $(foreach f, $(FILES), objects/$(f).o)

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = philo

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objects/%.o: sources/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:  
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)
	
re: fclean all

all: $(NAME)

.PHONY: all clean fclean re