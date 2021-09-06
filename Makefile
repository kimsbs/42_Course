SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk
SERVER_OBJ = server.o
CLIENT_OBJ = client.o


all : $(NAME)

$(NAME)	: $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) 
	$(CC) $< $(LIB) -o $@
	
$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $< $(LIB) -o $@
	
%.o : %.c
	$(CC) $(FLAGS) $< -o $@ 

clean :
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all