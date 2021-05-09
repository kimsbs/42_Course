NAME = libft.a
SRCS = ft_isascii.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
			 ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strlcat.c \
			 ft_strrchr.c ft_bzero.c ft_isprint.c ft_memmove.c \
			 ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_memccpy.c \
			 ft_memset.c ft_strlen.c ft_toupper.c ft_isalpha.c \
			 ft_memchr.c ft_strchr.c ft_strncmp.c ft_calloc.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
