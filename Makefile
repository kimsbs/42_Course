SERVER			= server
CLIENT			= client
SERVER_BONUS	= server_bonus
CLIENT_BONUS	= client_bonus
CC				= gcc -Wall -Werror -Wextra
NAME			= minitalk
BONUS			= 
SERVER_OBJ		= server.o
CLIENT_OBJ		= client.o
SBONUS_OBJ		= server_bonus.o
CBONUS_OBJ		= client_bonus.o

%.o: %.c
	$(CC) -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) 
	$(CC) -o $@ $<
	
$(CLIENT) : $(CLIENT_OBJ)
	$(CC) -o $@ $<

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(SBONUS_OBJ) 
	$(CC) -o $@ $<

$(CLIENT_BONUS) : $(CBONUS_OBJ)
	$(CC) -o $@ $<

clean :
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)
	rm -f $(SBONUS_OBJ)
	rm -f $(CBONUS_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all