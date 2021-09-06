SERVER   = server
CLIENT   = client
CC	     = gcc -Wall -Werror -Wextra
NAME     = minitalk
SERVER_OBJ = server.o
CLIENT_OBJ = client.o

%.o: %.c
	$(CC) -c $< -o $@

all : $(NAME)

$(NAME)	: $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) 
	$(CC) -o $@ $<
	
$(CLIENT) : $(CLIENT_OBJ)
	$(CC) -o $@ $<

clean :
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all