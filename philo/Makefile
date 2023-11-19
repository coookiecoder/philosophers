files = main ft_ullatoi simulation life check_alive

sources = $(foreach buffer, $(files), $(buffer).c)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = philo

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(sources) -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

