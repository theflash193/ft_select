MAIN	:= parser.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
