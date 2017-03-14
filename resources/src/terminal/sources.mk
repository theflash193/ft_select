MAIN	:= termios.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRTERMINAL)/%.c $(HEAD)
	$(COMPIL)
