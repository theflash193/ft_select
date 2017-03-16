MAIN	:= set_terminal.c reset_terminal.c get_terminal_dimension.c \
	configuration_terminal.c get_tty_name.c 
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRTERMINAL)/%.c $(HEAD)
	$(COMPIL)
