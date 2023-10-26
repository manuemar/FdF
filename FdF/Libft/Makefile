 NAME = libft.a

INCLUDE = libft.h

MY_SOURCES = ft_atoi.c \
			 ft_bzero.c \
			 ft_calloc.c \
			 ft_isalnum.c \
			 ft_isalpha.c \
			 ft_isascii.c \
			 ft_isdigit.c \
			 ft_isprint.c \
			 ft_itoa.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c \
			 ft_putchar_fd.c \
			 ft_putnbr_fd.c \
			 ft_putendl_fd.c \
			 ft_putstr_fd.c \
			 ft_split.c \
			 ft_strchr.c \
			 ft_strdup.c \
			 ft_striteri.c \
			 ft_strjoin.c \
			 ft_strlcat.c \
			 ft_strlcpy.c \
			 ft_strlen.c \
			 ft_strmapi.c \
			 ft_strncmp.c \
			 ft_strnstr.c \
			 ft_strrchr.c \
			 ft_strtrim.c \
			 ft_substr.c \
			 ft_tolower.c \
			 ft_toupper.c

#BONUS =

PRINTF = ./Printf/ft_printf.c \
		 ./Printf/ft_print_chars.c \
		 ./Printf/ft_print_deci.c \
		 ./Printf/ft_print_hexa.c

GNL = ./GetNextLine/get_next_line.c \
	  ./GetNextLine/get_next_line_utils.c

MY_OBJECTS = $(MY_SOURCES:.c=.o) $(PRINTF:.c=.o) $(GNL:.c=.o)
#BONUS_OBJS	= ${BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(INCLUDE)
	@ar rcs $(NAME) $(MY_OBJECTS)

#bonus: ${MY_OBJECTS} ${BONUS_OBJS}
#	@ar r ${NAME} ${MY_OBJECTS} ${BONUS_OBJS}

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
