NAME = get_next_line

MY_SOURCES = get_next_line.c \
			 get_next_line_utils.c \
			 main.c

BONUS =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
BONUS_OBJS	= ${BONUS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

test : $(NAME)
	./$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(MY_SOURCES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

cclean:
	rm -f a.out get_next_line.h.gch

gcc:
	$(CC) $(CFLAGS) $(MY_SOURCES)
	./a.out

bonus: #${MY_OBJECTS} ${BONUS_OBJS}
	$(CC) $(CFLAGS) $(BONUS) -o $(NAME)
	./$(NAME)
#	@ar r ${NAME} ${MY_OBJECTS} ${BONUS_OBJS}

.PHONY: all clean fclean re gcc
