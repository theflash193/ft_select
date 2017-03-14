MAIN	:= signal_handler.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRSIGNAL)/%.c $(HEAD)
	$(COMPIL)
